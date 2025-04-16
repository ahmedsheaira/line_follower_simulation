cmake_minimum_required(VERSION 3.22)
project(LineFollowerSimulation)

# Set C++ standard to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Set the source files
set(SRC_FILES
    src/control_strategy.cpp
    src/main.cpp
    src/motor_controller.cpp
    src/robot.cpp
    src/sensor_array.cpp
)

# Main executable
add_executable(LineFollowerSimulation ${SRC_FILES})

# Add include directory
target_include_directories(LineFollowerSimulation PUBLIC include/)
