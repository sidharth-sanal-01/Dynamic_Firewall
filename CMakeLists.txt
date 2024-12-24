# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(DynamicFirewall)

# Find D-Bus using pkg-config
find_package(sdbus-c++ REQUIRED)

# Include D-Bus headers

include_directories(${SDBUS_INCLUDE_DIRS})
include_directories(include)
# Get all header and source files in src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")



# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE SDBusCpp::sdbus-c++)