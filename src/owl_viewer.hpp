#ifndef OWL_VIEWER_HPP
#define OWL_VIEWER_HPP
#pragma once

// Standard includes
#include <memory>

// Third-party includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ov
{
    class OwlViewer
    {
    private:
        // GLFW window reference
        std::unique_ptr<GLFWwindow*> m_window;
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
    };
    
} // namespace ov



#endif