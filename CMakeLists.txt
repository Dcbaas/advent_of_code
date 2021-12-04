# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("advent_of_code")

# Include sub-projects.
add_subdirectory(common)
add_subdirectory(ch1)
add_subdirectory(ch2)
