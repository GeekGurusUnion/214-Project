cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

# Enable testing
enable_testing()

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Define sources for the main project
set(PROJECT_SOURCES
        main.cpp
        kitchen/fa_dish.h
        kitchen/ca_handler.h
        kitchen/si_headChef.h
        kitchen/fa_dishFactory.h
        kitchen/fa_dishFactory.cpp
        kitchen/ad_OrderAdapter.h
        kitchen/ca_ingredientHandler.h
        kitchen/fa_burger.h
        kitchen/ad_RestaurantOrder.cpp
        kitchen/ad_FloorOrder.cpp
        kitchen/ad_OrderAdapter.cpp
        kitchen/si_headChef.cpp
        kitchen/fa_dish.cpp
        kitchen/fa_Pizza.h
)

# Define sources for the tests
set(TEST_SOURCES
        kitchen/factory_unittest.cpp
        kitchen/headChef_unittest.cpp
        kitchen/headChefTest.cpp
        kitchen/factoryTest.cpp
        kitchen/fa_dish.h
        kitchen/ca_handler.h
        kitchen/si_headChef.h
        kitchen/fa_dishFactory.h
        kitchen/fa_dishFactory.cpp
        kitchen/ad_OrderAdapter.h
        kitchen/ca_ingredientHandler.h
        kitchen/fa_burger.h
        kitchen/ad_RestaurantOrder.cpp
        kitchen/ad_FloorOrder.cpp
        kitchen/ad_OrderAdapter.cpp
        kitchen/si_headChef.cpp
        kitchen/fa_dish.cpp
        kitchen/fa_Pizza.h
        test_main.cpp
)

# Define the main executable
add_executable(FlyweightFighters_COS214_Project ${PROJECT_SOURCES})

# Set up the linter
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Define the test executable
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Use the Threads package
find_package(Threads)
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)

# Define the Valgrind test
add_test(
        NAME runTestsValgrind
        COMMAND valgrind --leak-check=full --error-exitcode=1 ./runTests
)
