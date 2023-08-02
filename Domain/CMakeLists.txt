# CMakeList.txt : CMake project for Prueba_2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library(domain_library
"Course.cpp"
"Course.h"
"Student.cpp"
"Student.h"
 "CourseDecorators/LimitedDecorator.cpp" "CourseDecorators/LimitedDecorator.h"  "CourseDecorators/ICourseDecorator.cpp"   "ICourse.h" "CourseDecorators/CorrelativeDecorator.h" "CourseDecorators/CorrelativeDecorator.cpp" "CourseDecorators/WithCounterDecorator.h" "CourseDecorators/WithCounterDecorator.cpp")

add_subdirectory("CourseDecorators")

target_include_directories(domain_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# TODO: Add tests and install targets if needed.
