# Find all dependencies
find_package(OpenGL REQUIRED)

# Create main application
add_executable(
    owl_viewer
    "logging.hpp"
    "logging.cpp"
    "owl_viewer.hpp"
    "owl_viewer.cpp"
    "runner.cpp"
)

add_dependencies(
    owl_viewer
    glfw
    glm
    glad
    spdlog
)

target_link_libraries(
    owl_viewer
    glfw
    glm
    glad
    OpenGL::GL
    spdlog
)