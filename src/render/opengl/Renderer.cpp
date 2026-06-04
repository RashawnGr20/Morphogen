#include "Renderer.h"
#include <iostream>

void Renderer::initialize()
{
    std::cout << "intializing renderer...\n"; 
}

void Renderer::render(int frameCount)
{
    std::cout << "begin render for frame : " << frameCount << "\n"; 
}

void Renderer::shutdown()
{
    std::cout << "shutting down...\n";
}