// Local includes
#include "owl_viewer.hpp"

#include "logging.hpp"

namespace ov 
{
    // Error callback
    static void error_callback(int error, const char* description)
    {
        OV_ERROR("Error code {}: {}", error, description);
    }

    // Keypress callback
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        OV_TRACE("Key pressed:");
        OV_TRACE("KEY: {} MODS: {}", key, mods);
    }


    OwlViewer::OwlViewer()
    {
        // Initialize the logger
        Logging::Init();

        // Set the error callback
        glfwSetErrorCallback(error_callback);

        // Initialize GLFW
        if (!glfwInit())
        {
            OV_FATAL("Unable to initialize OpenGL context");
            exit(EXIT_FAILURE);
        }

        // Create the window
        m_window = std::make_unique<GLFWwindow*>(glfwCreateWindow(640, 480, "OwlViewer", nullptr, nullptr));
        if (!m_window)
        {
            OV_FATAL("Unable to create window");
            exit(EXIT_FAILURE);
        }

        // Make the OpenGL context current
        glfwMakeContextCurrent(*m_window);
        gladLoadGL();

        // Set the keypress callback
        glfwSetKeyCallback(*m_window, key_callback);

        // V-sync
        glfwSwapInterval(1);

        // Window loop
        while (!glfwWindowShouldClose(*m_window))
        {
            // Draw stuff here

            // Update/render changes
            glfwSwapBuffers(*m_window);

            // Poll for events
            glfwPollEvents();
        }

    }

    OwlViewer::~OwlViewer()
    {
        glfwDestroyWindow(*m_window);
        glfwTerminate();
    }

} // namepsace ov