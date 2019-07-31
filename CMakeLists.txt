cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/src")


file(GLOB sources src/*.cpp src/*.h)
add_executable(app ${sources})
