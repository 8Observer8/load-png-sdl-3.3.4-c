cmake_minimum_required(VERSION 3.21)
project(load-png-sdl-3.3.4-c)
add_executable(app)

# Specify where the application source files are stored
target_sources(app
PRIVATE
    src/main.c
)

# Check for WebAssembly
if (CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    target_link_options("app" PRIVATE "SHELL:--embed-file ${CMAKE_CURRENT_SOURCE_DIR}/assets/textures/crate.png@/assets/textures/crate.png")
    set_property(TARGET "app" APPEND PROPERTY LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/assets/textures/crate.png")
endif()

# Check for Windows
if (WIN32)
    target_link_options(app PRIVATE -static)
endif()

find_package(SDL3)
find_package(SDL3_image)
target_link_libraries(app PRIVATE SDL3_image::SDL3_image SDL3::SDL3)

# For comments:
#[===[
# Some content here
#]===]
