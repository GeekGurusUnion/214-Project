cmake_minimum_required(VERSION 2.6)

# Enable testing
enable_testing()

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TESTING_CODE_SOURCES *.h)
file(GLOB TESTING_CODE_HEADERS *.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${TESTING_CODE_SOURCES} ${TESTING_CODE_HEADERS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

find_package(Threads)
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)

# Define the Valgrind test
add_test(
    NAME runTestsValgrind
    COMMAND valgrind --leak-check=full --error-exitcode=1 ./runTests
)
