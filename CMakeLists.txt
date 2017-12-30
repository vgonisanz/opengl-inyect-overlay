cmake_minimum_required (VERSION 2.8.12)

# Project step I: Check dependencies
# ------------------------------------------------------------------------------------------------------
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)
include(FindFreetype)

if(${FREETYPE_FOUND})
    message("Dependencies: Freetype found!")
else()
    message(FATAL_ERROR "Dependencies: Freetype not found!")
endif()

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

# Project step II: Set up project name
# ------------------------------------------------------------------------------------------------------
set(PROJ_MAIN_NAME opengl-steamlike-overlay)

set(RESOURCES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources" CACHE PATH "Setting resources path" FORCE)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "Changing default install path" FORCE)
endif()

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")


# Project step III: Add modules
# ------------------------------------------------------------------------------------------------------
add_subdirectory(modules)

# Project step IV: Add examples
# ------------------------------------------------------------------------------------------------------
add_subdirectory(examples)
