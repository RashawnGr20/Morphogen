#pragma once 
#include "Window.h"

class Renderer 
{ 
    public : 
        void initialize();
        void render(int frameCount);
        void shutdown();
        bool shouldClose(); 

    private : 
        Window window; 
};