# CMakeList.txt : CMake project for Prueba_2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

add_executable(test_decorators "TestDecorators.cpp")

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(test_decorators PRIVATE Catch2::Catch2WithMain)
target_link_libraries(test_decorators PRIVATE domain_library)

# TODO: Add tests and install targets if needed.
