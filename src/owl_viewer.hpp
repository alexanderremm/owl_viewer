#ifndef OWL_VIEWER_HPP
#define OWL_VIEWER_HPP
#pragma once

// Third-party includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard includes
#include <memory>
#include <string>

namespace ov
{
    class OwlViewer
    {
    private:
        // GLFW window reference
        std::unique_ptr<GLFWwindow*> m_window;
        std::string m_glsl_version = "#version 150";
    public:
        /**
         * @brief Construct a new Owl Viewer object
         * 
         */
        OwlViewer();

        /**
         * @brief Destroy the Owl Viewer object
         * 
         */
        ~OwlViewer();

        // Non-copyable
        OwlViewer(const OwlViewer& other) = delete;
        OwlViewer& operator=(const OwlViewer& other) = delete;

        // Non-moveable
        OwlViewer(OwlViewer&& other) = delete;
        OwlViewer& operator=(OwlViewer&& other) = delete;

    private:
        void CreateWindow();
        void ToolbarUI();
    };
    
} // namespace ov



#endif