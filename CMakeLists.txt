cmake_minimum_required(VERSION 3.27)
project(template_vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(template_vector
        main.cpp
        task.h
        asserts.h
        menu.h
        DynamicArray&List.h
        ImmutableLinkedList.h
        Queue.h
        Heap.h
)
