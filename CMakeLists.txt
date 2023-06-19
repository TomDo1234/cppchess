# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(MyChessProject VERSION 1.0.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable target with source files
add_executable(MyChessApp src/main.cpp src/piece.cpp src/ce.cpp src/zobrist.cpp)
