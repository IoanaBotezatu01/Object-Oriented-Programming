cmake_minimum_required(VERSION 3.24)
project(BuildYourCar)

set(CMAKE_CXX_STANDARD 17)

add_executable(BuildYourCar main.cpp Service.h Car.cpp ElectricEngine.cpp Engine.h Service.cpp TurboEngine.cpp Engine.cpp Ui.h Ui.cpp)
