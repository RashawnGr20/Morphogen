#pragma once 
#include <GLFW/glfw3.h>

class Window { 


    public :

        Window(); 

        void create();
        void pollEvents();
        void swapBuffers(); 
        bool shouldClose(); 
        void shutdown(); 
    
    private : 
        GLFWwindow* handle; 

}; 