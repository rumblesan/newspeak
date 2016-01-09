cmake_minimum_required(VERSION 3.0)
project(newspeak)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

include_directories(main/include)

add_subdirectory(main)

