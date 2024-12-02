# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(DynamicFirewall)

# Add include directory
include_directories(include)

# Get all header and source files in src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})