#include "Renderer.h"
#include <iostream>
#include <GLFW/glfw3.h>

void Renderer::initialize()
{
    std::cout << "initializing renderer...\n"; 
    window.create();
}

void Renderer::render(int frameCount)
{
    window.pollEvents();

    if (frameCount % 60 == 0 ) { 
        std::cout << "begin render for frame : " << frameCount << "\n"; 
    }

    glClearColor(0.54f, 0.60f, 0.36f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); 

    window.swapBuffers(); 
}

void Renderer::shutdown()
{
    std::cout << "shutting down...\n";
    window.shutdown(); 
}

bool Renderer::shouldClose() {
    return window.shouldClose(); 
}