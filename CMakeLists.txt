cmake_minimum_required(VERSION 3.24)
project(oop_4term)

set(CMAKE_CXX_STANDARD 17)

#for lab2
#add_executable(oop_4term lab1/Main.cpp lab1/Matrix.cpp lab1/Matrix.h)

#for lab2
add_executable(oop_4term  lab2/Main.cpp lab2/Point.h lab2/Point.cpp lab2/Line.cpp lab2/Line.h lab2/GroupOfLines.h lab2/GroupOfLines.cpp)
