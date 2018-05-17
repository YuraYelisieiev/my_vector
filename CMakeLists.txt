cmake_minimum_required(VERSION 3.10)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector main.cpp myvector.h myvector_impl.h memory_handle_impl.h memory_handle.h)