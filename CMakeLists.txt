cmake_minimum_required(VERSION 3.23)
project(QueensCore)

set(CMAKE_CXX_STANDARD 20)

add_executable(QueensCore main.cpp post_class.h post_class.cpp)

target_link_libraries(QueensCore Ws2_32)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
