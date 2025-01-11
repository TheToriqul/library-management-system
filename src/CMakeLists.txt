# Minimum CMake version required
cmake_minimum_required(VERSION 3.5.0)

# Project name and version
project(Library-Management-System VERSION 0.1.0 LANGUAGES C CXX)

# Add executable target
add_executable(Library-Management-System main.cpp)

# Enable testing support
include(CTest)
enable_testing()

# Package configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)