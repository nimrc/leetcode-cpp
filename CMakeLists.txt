cmake_minimum_required(VERSION 3.14)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

file(GLOB SRC *.cpp)

foreach (file ${SRC})
    get_filename_component(smp ${file} NAME_WE)
    add_executable(${smp} ${file})
endforeach ()
