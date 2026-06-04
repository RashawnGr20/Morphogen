#pragma once 
#include "Renderer.h"

class Engine 
{

    public:
        void run(); 
        Engine();

    private : 
        bool isRunning;
        int frameCount; 
        void update(); 

        Renderer renderer; 
        
        void shutdown(); 
        void initialize();    
        
}; 