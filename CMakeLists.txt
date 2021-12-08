# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project ("advent_of_code")

# Include sub-projects.
add_subdirectory(common)
add_subdirectory(ch1)
add_subdirectory(ch2)
add_subdirectory(ch3)
add_subdirectory(ch4)
