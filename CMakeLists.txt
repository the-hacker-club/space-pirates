cmake_minimum_required(VERSION 3.14)
project(SpacePirates VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl")

add_subdirectory(WarpEngine)
add_subdirectory(SpacePirates)
