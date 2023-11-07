cmake_minimum_required(VERSION 3.25)
project(FlyweightFighters_COS214_Project)

# Use file GLOB to find all source and header files
file(GLOB_RECURSE ALL_SOURCES "*.cpp")
file(GLOB_RECURSE ALL_HEADERS "*.h")

# Exclude any unitTest*.cpp files from the list of sources
list(FILTER ALL_SOURCES EXCLUDE REGEX "unitTest.*\\.cpp$")

# Now define the executable including only the main.cpp and other sources
add_executable(FlyweightFighters_COS214_Project ${ALL_SOURCES} ${ALL_HEADERS})

# Set up the linter
set(CMAKE_CXX_CLANG_TIDY clang-tidy)
