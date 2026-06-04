#include "Renderer.h"
#include <iostream>

void Renderer::initialize()
{
    std::cout << "initializing renderer...\n"; 
    window.create();
}

void Renderer::render(int frameCount)
{
    window.pollEvents();

    std::cout << "begin render for frame : " << frameCount << "\n"; 
   

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