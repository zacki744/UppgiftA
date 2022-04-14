# CMakeList.txt : CMake project for UppgiftA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("sorting")

# Add source to this project's executable.
add_executable (sorting "Sorting.h" "main.cpp")

# TODO: Add tests and install targets if needed.
