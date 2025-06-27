#pragma once
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>

// Forward declare GLFWwindow
struct GLFWwindow;

namespace SourceEngine {
    // Engine info
    void PrintEngineInfo();

    // Initialization
    void InitEngine();
    void InitWindow(const std::string& title, int width, int height);

    // Rendering
    void ClearScreen();
    void SwapBuffers();

    // Handle window cleanup
    void Terminate();

    // Internal window pointer
    extern GLFWwindow* window;
}
