# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(DynamicFirewall)

# Find D-Bus using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(DBUS REQUIRED dbus-1)

# Include D-Bus headers
include_directories(${DBUS_INCLUDE_DIRS} include)

# Link D-Bus libraries
link_directories(${DBUS_LIBRARY_DIRS})
add_definitions(${DBUS_CFLAGS_OTHER})

# Get all header and source files in src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")



# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${DBUS_LIBRARIES})