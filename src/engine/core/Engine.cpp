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

}

void Engine::run()
{
    initialize(); 
    isRunning = true; 
    std::cout << "engine is running\n";
    
    while(isRunning && !renderer.shouldClose()) { 
        update();   
        renderer.render(frameCount);

        frameCount += 1;
    
        if (frameCount >= 5) {
            isRunning = false; 
        }
    }
    shutdown(); 
}

Engine::Engine() 
{
    std::cout << "engine created\n";
    isRunning = false;  
    frameCount = 0; 
}


