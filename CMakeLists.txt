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
include(FetchContent)
FetchContent_Declare(eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0)
FetchContent_MakeAvailable(eigen)

target_link_libraries(arm Eigen3::Eigen)