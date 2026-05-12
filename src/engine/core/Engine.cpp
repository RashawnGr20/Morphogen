#include "Engine.h"
#include <iostream>

void Engine::initialize() 
{
    frameCount = 0; 
    std::cout << "starting initialization\n"; 

}


void Engine::shutdown()
{
    std::cout << "engine is shutdown\n"; 

}

void Engine::update() 
{ 
    std::cout << "current frame: " << frameCount << "\n"; 

    frameCount += 1;
    
    if (frameCount >= 5) {
        isRunning = false; 
    }
}

void Engine::run()
{
    initialize(); 
    isRunning = true; 
    std::cout << "engine is running\n";
    
    while(isRunning) { 
        update(); 
    }
    shutdown(); 
}

Engine::Engine() 
{
    std::cout << "engine created\n";
    isRunning = false;  
    frameCount = 0; 
}


