#include "Window.h"
#include <iostream>

void Window::create() {

    if (!glfwInit()) { 
        std::cout << "failed to initialize GLFW\n"; 
        return; 
    }

    handle = glfwCreateWindow(width, height, title, nullptr, nullptr); 

    if (!handle) {
        std::cout << "Failed to create window\n"; 
        glfwTerminate();
        return; 
    }

    glfwMakeContextCurrent(handle); 
    
    std::cout << "window created\n";
}

void Window::pollEvents() 
{ 
    glfwPollEvents(); 

}

void Window::swapBuffers() 
{ 
    if (handle) { 
        glfwSwapBuffers(handle);
    }
     
}

bool Window::shouldClose() { 
    
    return handle && glfwWindowShouldClose(handle);    
}

void Window::shutdown() 
{ 
   if (handle)  { 
    glfwDestroyWindow(handle); 
    handle = nullptr; 
   }

   glfwTerminate(); 
   std::cout << "window shutdown\n";  
}


Window::Window() { 
    handle = nullptr; 
    width = 800; 
    height = 600; 
    title = "MORPHOGEN"; 
}
