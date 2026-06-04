#pragma once 

class Window { 

    public : 
        void create();
        void pollEvents();
        void swapBuffers(); 
        bool shouldClose(); 
        void shutdown(); 

}; 