cmake_minimum_required(VERSION 3.24)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskManager main.cpp domain.cpp domain.h Repository.cpp Repository.h Ui.cpp Ui.h Service.cpp Service.h)
