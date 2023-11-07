cmake_minimum_required(VERSION 3.25)
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

# Use file GLOB to find all source and header files
file(GLOB_RECURSE ALL_SOURCES "*.cpp")
file(GLOB_RECURSE ALL_HEADERS "*.h")

# Exclude main.cpp from the sources
list(FILTER ALL_SOURCES EXCLUDE REGEX "^(.*\\/)?main\\.cpp$")

# Set the PROJECT_SOURCES based on filtered results
set(PROJECT_SOURCES ${ALL_HEADERS} ${ALL_SOURCES})

# Define the main executable
add_executable(FlyweightFighters_COS214_Project ${PROJECT_SOURCES})

# Set up the linter
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Helper macro to add test executables
macro(package_add_test TESTNAME FILES)
    add_executable(${TESTNAME} ${FILES})
    target_link_libraries(${TESTNAME} gtest gtest_main gmock gmock_main pthread)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
endmacro()

# Add test executables
package_add_test(unitTest_Facade unitTest_Facade.cpp)
package_add_test(unitTests_Dawie unitTests_Dawie.cpp)
package_add_test(unitTests_Iwan unitTests_Iwan.cpp)
package_add_test(unitTests_Stephan unitTests_Stephan.cpp)
package_add_test(unitTests_Tiaan unitTests_Tiaan.cpp)
package_add_test(unitTests_Xavier unitTests_Xavier.cpp) # Assuming you have a file named unitTests_Xavier.cpp

# Define the Valgrind test for the main executable
add_test(
        NAME FlyweightFighters_COS214_Project_Valgrind
        COMMAND valgrind --leak-check=full --error-exitcode=1 $<TARGET_FILE:FlyweightFighters_COS214_Project>
)

# Include directories for the test targets
foreach(TEST_TARGET unitTest_Facade unitTests_Dawie unitTests_Iwan unitTests_Stephan unitTests_Tiaan unitTests_Xavier)
    target_include_directories(${TEST_TARGET} PRIVATE ${CMAKE_SOURCE_DIR})
endforeach()

# Define the Valgrind test
add_test(
        NAME runTestsValgrind
        COMMAND valgrind --leak-check=full --error-exitcode=1 ./runTests
)
