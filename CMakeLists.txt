# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Decorator_Example")

# Include sub-projects.
add_subdirectory ("Domain")
add_subdirectory ("Tests")
