#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Globals.h"

// Function prototypes
void initOpenGL();
void setupViewport(GLFWwindow* window, int width, int height);
void render();

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Set OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, ENGINE_NAME, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }

    // Setup OpenGL options
    initOpenGL();

    // Set up the viewport
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    setupViewport(window, screenWidth, screenHeight);

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Render
        render();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up
    glfwTerminate();
    return 0;
}

void initOpenGL() {
    // Set clear color
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void setupViewport(GLFWwindow* window, int width, int height) {
    // Set the viewport size
    glViewport(0, 0, width, height);
}

void render() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Render code goes here

    // Example: Render a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}