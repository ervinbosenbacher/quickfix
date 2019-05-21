cmake_minimum_required(VERSION 3.14.3)
project(pyfix)

include_directories(pyfix ../../include)


add_subdirectory(pybind11)
pybind11_add_module(pyfix quickfix.cpp)
target_link_libraries(pyfix PRIVATE quickfix)
