cmake_minimum_required(VERSION 3.10)

project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

enable_testing()

file(GLOB SRC src/*.cpp)

foreach (file ${SRC})
    get_filename_component(smp ${file} NAME_WE)
    add_executable(${smp} ${file})
    add_test(NAME ${smp} COMMAND ${smp})
endforeach ()
