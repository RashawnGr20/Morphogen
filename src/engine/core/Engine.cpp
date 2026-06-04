#include "Engine.h"
#include <iostream>

void Engine::initialize() 
{
    frameCount = 0; 
    renderer.initialize(); 

}


void Engine::shutdown()
{
    std::cout << "engine shutdown\n"; 
    renderer.shutdown(); 

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
        renderer.render(frameCount);
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


