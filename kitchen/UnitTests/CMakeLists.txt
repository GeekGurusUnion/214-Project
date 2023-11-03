cmake_minimum_required(VERSION 2.6)

add_subdirectory(FactoryCode)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB FACTORY_CODE_SOURCES "FactoryCode/*.cpp")
file(GLOB FACTORY_CODE_HEADERS "FactoryCode/*.h")
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main.cpp factoryTest.h factoryTest.cpp factory_unittest.cpp ${FACTORY_CODE_SOURCES} ${FACTORY_CODE_HEADERS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

find_package(Threads)
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)
