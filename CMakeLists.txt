cmake_minimum_required(VERSION 3.26)
project(Login_and_Registration_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Login_and_Registration_System main.cpp
        UserLogin.h
        UserLogin.cpp)
