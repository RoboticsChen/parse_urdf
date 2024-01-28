project(get_urdf)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/..)
add_executable(parse demo.cpp ${CMAKE_SOURCE_DIR}/../parse_urdf.cpp)