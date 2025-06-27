#include "include/SourceEngine/SourceEngine.hpp"
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h> // Add GLFW here

namespace SourceEngine {

GLFWwindow* window = nullptr; // Needed to use SwapBuffers

void PrintEngineInfo() {
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
}

void InitEngine() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Engine initialized with GLFW." << std::endl;
}

void InitWindow(const std::string& title, int width, int height) {
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    std::cout << "Window created: " << title << " (" << width << "x" << height << ")" << std::endl;

    // Optional: Enable VSync
    glfwSwapInterval(1);

    // Print GL version after context is ready
    PrintEngineInfo();
}

void ClearScreen() {
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f); // Dark blueish background
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SwapBuffers() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Terminate() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

} // namespace SourceEngine

