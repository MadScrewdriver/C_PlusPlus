cmake_minimum_required(VERSION 3.9)
project(Codewars)

set(CMAKE_CXX_STANDARD 11)

add_executable(Codewars testy.cpp "Jumping _Number_7.cpp" "Special_Number_7.cpp")
add_executable(testy testy.cpp)
add_executable(Roman_Numerals_Encoder_4 Roman_Numerals_Encoder_4.cpp)