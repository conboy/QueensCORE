cmake_minimum_required(VERSION 3.23)
project(QueensCore)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(BOOST_INCLUDE_LIBRARIES beast)
set(BOOST_ENABLE_CMAKE ON)

FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.80.0
)

FetchContent_MakeAvailable(Boost)

add_executable(QueensCore main.cpp post_class.h post_class.cpp)

target_link_libraries(QueensCore PUBLIC ws2_32 PRIVATE Boost::beast)