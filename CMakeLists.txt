cmake_minimum_required(VERSION 3.20) # For C++23 (2b) support

# Set version to C++23, enable more warnings and go for maximum optimizations.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
add_compile_options(-Wall -Wextra -pedantic -O3)

# Change this name later
project(setup VERSION 0.1.0)

add_subdirectory(fmt)
add_subdirectory(random)
add_subdirectory(scnlib)

# Change this name later
add_executable(setup main.cpp)

# Add libraries
target_link_libraries(setup fmt::fmt scn::scn effolkronium_random)
