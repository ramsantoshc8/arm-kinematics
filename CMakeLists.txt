cmake_minimum_required(VERSION 3.16)
project(ArmKinematics CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()
include_directories(include)

add_executable(arm src/main.cpp)