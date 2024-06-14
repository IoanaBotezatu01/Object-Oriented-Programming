cmake_minimum_required(VERSION 3.24)
project(RealEstateAgency)

set(CMAKE_CXX_STANDARD 17)

add_executable(RealEstateAgency main.cpp Client.h RealEstateAgency.h Person.h Company.h Ui.h Dwelling.h Client.cpp Person.cpp Company.cpp)
