cmake_minimum_required(VERSION 3.0)
project(newspeak)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

add_subdirectory(main)
add_subdirectory(lib)

option (WITH_TESTS "build tests" ON)

if (WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

