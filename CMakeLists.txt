cmake_minimum_required(VERSION 3.23) # CMake Version
project(QueensCore) # Project name

set(CMAKE_CXX_STANDARD 20)

# Allows CMake to get external libraries from the internet
include(FetchContent)
set(BOOST_INCLUDE_LIBRARIES beast)
set(BOOST_ENABLE_CMAKE ON)

# Fetch Boost which comes with beast
FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.80.0
)

# Install boost
FetchContent_MakeAvailable(Boost)

# Create executable called QueensCore that includes the following executables
add_executable(QueensCore main.cpp post_class.h post_class.cpp sqlite3.h sqlite3.c post_collection.cpp post_collection.h)

# Link the following libraries to the executable
target_link_libraries(QueensCore PUBLIC ws2_32 PRIVATE Boost::beast)