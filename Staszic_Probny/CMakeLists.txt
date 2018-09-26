cmake_minimum_required(VERSION 3.10)
project(Staszic_Probny)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)


add_executable(Przeprowadzka Przeprowadzka.cpp)