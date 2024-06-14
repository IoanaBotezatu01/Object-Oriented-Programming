cmake_minimum_required(VERSION 3.24)
project(Hospital)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hospital main.cpp Service.h HospitalDepartment.h Surgery.h NeonatalUnit.h HospitalDepartment.cpp Surgery.cpp)
