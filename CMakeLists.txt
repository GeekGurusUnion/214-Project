cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(googletest)

# Now that we have fetched the content, add the subdirectories for GoogleTest and GoogleMock
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# Use file GLOB to find all source and header files, excluding unitTest*.cpp and main.cpp for the test sources
file(GLOB_RECURSE ALL_SOURCES "*.cpp")
file(GLOB_RECURSE ALL_HEADERS "*.h")

# Exclude files starting with unitTest and main.cpp for the PROJECT_SOURCES
list(FILTER ALL_SOURCES EXCLUDE REGEX "unitTest.*\\.cpp$")
list(FILTER ALL_SOURCES EXCLUDE REGEX "main\\.cpp$")

# Set the PROJECT_SOURCES based on filtered results
set(PROJECT_SOURCES ${ALL_HEADERS} ${ALL_SOURCES})

# Exclude files starting with unitTest for the TEST_SOURCES
file(GLOB_RECURSE TEST_SOURCES "*.cpp")
file(GLOB_RECURSE TEST_HEADERS "*.h")

# Exclude main.cpp from the TEST_SOURCES
list(FILTER TEST_SOURCES EXCLUDE REGEX "main\\.cpp$")

# Define the main executable
add_executable(FlyweightFighters_COS214_Project ${PROJECT_SOURCES})

# Set up the linter
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Define the test executable
add_executable(runTests ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(runTests gtest gtest_main gmock gmock_main pthread)

# Define the Valgrind test
add_test(
        NAME runTestsValgrind
        COMMAND valgrind --leak-check=full --error-exitcode=1 ./runTests
)
