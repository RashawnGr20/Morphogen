#pragma once 

class Engine 
{

    public:
        void run(); 
        Engine();

    private : 
        bool isRunning;
        int frameCount; 
        void update(); 
        void shutdown(); 
        void initialize();    
        
}; 