// Local includes
#include "owl_viewer.hpp"

#include "logging.hpp"

// Third-party includes
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


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

        // Initialize the window
        CreateWindow();

        // Window loop
        while (!glfwWindowShouldClose(*m_window))
        {
            // Poll for events
            glfwPollEvents();
            
            // Clear the screen
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Feed data to ImGui and start the frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Draw stuff here
            ToolbarUI();

            // Update/render changes
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            glfwSwapBuffers(*m_window);
        }

    }

    OwlViewer::~OwlViewer()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(*m_window);
        glfwTerminate();
    }

    void OwlViewer::CreateWindow() 
    {
        // Set the error callback
        glfwSetErrorCallback(error_callback);

        // Initialize GLFW
        if (!glfwInit())
        {
            OV_FATAL("Unable to initialize OpenGL context");
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_DOUBLEBUFFER, 1);

        // Create the window
        m_window = std::make_unique<GLFWwindow*>(glfwCreateWindow(640, 480, "OwlViewer", nullptr, nullptr));
        if (!m_window)
        {
            OV_FATAL("Unable to create window");
            exit(EXIT_FAILURE);
        }

        // Make the OpenGL context current
        glfwMakeContextCurrent(*m_window);
        gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

        // ImGui loading and setup
        ImGui::CreateContext();
        IMGUI_CHECKVERSION();
        ImGuiIO &io {ImGui::GetIO()};
        ImGui_ImplGlfw_InitForOpenGL(*m_window, true);
        ImGui_ImplOpenGL3_Init(m_glsl_version.c_str());
        ImGui::StyleColorsDark();

        // Set the keypress callback
        glfwSetKeyCallback(*m_window, key_callback);

        // V-sync
        glfwSwapInterval(1);
    }

    void OwlViewer::ToolbarUI()
    {
        if(ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if(ImGui::MenuItem("Open"))
                {
                    // Open a file for viewing
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }

} // namepsace ov