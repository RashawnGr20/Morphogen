# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

Morphogen is a GPU-accelerated parametric design engine (C++17, targeting CUDA + OpenGL). The engine is at an early stage — right now it is a GLFW window with an OpenGL clear-color render loop driven by an `Engine`/`Renderer`/`Window` triple. Most of the source tree is scaffolding for where features are intended to land, not existing code.

The stack aspires to C++, CUDA, OpenGL, GLFW, Dear ImGui, and CMake. Only C++/OpenGL/GLFW/CMake are wired up so far — CUDA is not enabled in [CMakeLists.txt](CMakeLists.txt) (`LANGUAGES CXX` only), and ImGui is not linked. Adding either means editing the CMake target and its `target_link_libraries`.

## Build & run

Build is Ninja-driven out of `build/`. From the repo root:

```bash
cmake -S . -B build -G Ninja
```

```bash
cmake --build build
```

```bash
./build/Morphogen.exe
```

Toolchain on this machine is `D:/tools/ucrt64/bin/gcc.exe` (see [.vscode/settings.json](.vscode/settings.json)). `find_package(glfw3 REQUIRED)` must resolve — GLFW has to be discoverable to CMake (e.g. via UCRT64/MSYS2). `opengl32` is linked directly, so this build is Windows-specific.

There is no test runner yet — [tests/](tests/) is empty. Do not claim a test suite exists.

The VS Code task in [.vscode/tasks.json](.vscode/tasks.json) is a single-file gcc compile of the *currently open* file — it is unrelated to the real CMake build and should not be used to build the project.

## Architecture

The runtime is a single call chain — [main.cpp](src/application/main.cpp) constructs `Engine` and calls `run()`; that's it.

- [src/engine/core/Engine.{h,cpp}](src/engine/core/Engine.cpp) — owns the main loop (`initialize` → `while(isRunning && !renderer.shouldClose()) update()/render()` → `shutdown`), owns the `Renderer` by value, tracks `frameCount`.
- [src/render/opengl/Renderer.{h,cpp}](src/render/opengl/Renderer.cpp) — owns the `Window` by value and a `Vec3 clearColor`; each frame it polls window events, `glClear`s, and swaps buffers.
- [src/render/opengl/Window.{h,cpp}](src/render/opengl/Window.h) — thin GLFW wrapper (`create`, `pollEvents`, `swapBuffers`, `shouldClose`, `shutdown`).
- [src/engine/math/Vec3.h](src/engine/math/Vec3.h) — plain float3 struct.

Ownership goes Engine → Renderer → Window (composition by value, no smart pointers, no polymorphism). The renderer owns the window rather than the engine — new subsystems that don't belong to rendering should be siblings of `Renderer` inside `Engine`, not children of it.

Empty scaffolding — treat as "reserved namespace, not existing feature":
- [src/domains/architecture/](src/domains/architecture/) — first target domain (procedural architecture); README hints the engine will use a shared field-based (SDF) representation across geometry/rendering/simulation.
- [src/gpu/kernels/raymarch/](src/gpu/kernels/raymarch/) — where CUDA raymarch kernels are expected.
- [src/engine/math/sdf/camera/](src/engine/math/sdf/camera/) — SDF/camera math.
- [docs/architecture.md](docs/architecture.md), [docs/overview.md](docs/overview.md) — placeholder files, currently empty.

When you add a new `.cpp`, add it explicitly to the `add_executable(Morphogen ...)` list in [CMakeLists.txt](CMakeLists.txt) — the build does not glob sources. New include directories also need to be added to `target_include_directories`; the current include search paths are `src/engine/core`, `src/render/opengl`, `src/engine/math` (so headers across those dirs are included by bare filename, e.g. `#include "Vec3.h"` and `#include "Renderer.h"`).

## Notes on existing code

- [main.cpp](src/application/main.cpp) includes `Engine.h` with an absolute Windows path (`C:\Users\Rashawn\Morphogen\src\engine\core\Engine.h`). This works only on the current machine and should be changed to `"Engine.h"` if you touch the file, since `src/engine/core` is already an include dir.
- Class members are default-initialized in-body rather than via mem-init lists in several places (`Engine::Engine`, `Engine::initialize` setting `frameCount = 0`); the existing style is header-comment-free and slightly loose on `const`/init-order — match it when editing rather than aggressively refactoring.
