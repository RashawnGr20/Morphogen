#pragma once 
#include "Window.h"
#include "Vec3.h"

class Renderer 
{ 
    public :
        Renderer(); 
        void initialize();
        void render(int frameCount);
        void shutdown();
        bool shouldClose(); 

    private : 
        Window window;
        Vec3 clearColor;  

};