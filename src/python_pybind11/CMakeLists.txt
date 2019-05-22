cmake_minimum_required(VERSION 3.14.3)
project(pyfix)

include_directories(pyfix ../../include)

if (WIN32)
    include_directories(c:/WRK/Runtime/WPy64-3720/python-3.7.2.amd64/include)
    link_directories(c:/WRK/Runtime/WPy64-3720/python-3.7.2.amd64/libs)
endif(WIN32)

add_subdirectory(pybind11)
pybind11_add_module(pyfix quickfix.cpp)
target_link_libraries(pyfix PRIVATE quickfix)
