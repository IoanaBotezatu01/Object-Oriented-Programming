cmake_minimum_required(VERSION 3.24)
project(Test1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test1 main.cpp Protein.cpp Protein.h Repository.cpp Repository.h Service.cpp Service.h Ui.cpp Ui.h)
