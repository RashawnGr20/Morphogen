#include "Window.h"
#include <iostream>

void Window::create() {

    std::cout << "window created\n";
}

void Window::pollEvents() { 
    std::cout << "polling window events\n";

}

void Window::swapBuffers() { 

    std::cout << "swapping buffers\n"; 
}

bool Window::shouldClose() { 
    
    return false;    
}

void Window::shutdown() { 
    std::cout << "window shutting down\n";
}
