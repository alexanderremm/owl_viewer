# Set path to where the ImGui files are
set(IMGUI_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Compile as a static library
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH}/backends)

target_link_libraries("ImGui" glfw)