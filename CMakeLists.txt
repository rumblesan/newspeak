cmake_minimum_required(VERSION 3.0)
project(newspeak)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(main)
add_subdirectory(lib)
add_subdirectory(collections)

