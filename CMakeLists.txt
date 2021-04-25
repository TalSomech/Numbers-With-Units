cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

#add_compile_options(-std=c++2a -Werror -Wsign-conversion)
#add_executable(Demo Demo.cpp NumberWithUnits.hpp NumberWithUnits.cpp)
#add_executable(test1 NumberWithUnits.hpp NumberWithUnits.cpp StudentTest1.cpp doctest.h)
#add_executable(test3 NumberWithUnits.hpp NumberWithUnits.cpp StudentTest3.cpp doctest.h)
add_executable(test3 NumberWithUnits.hpp NumberWithUnits.cpp StudentTest2.cpp doctest.h)