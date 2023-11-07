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

# Define sources for the main project
set(PROJECT_SOURCES
        main.cpp
        fa_dish.h
        ca_handler.h
        si_headChef.h
        fa_dishFactory.h
        fa_dishFactory.cpp
        ad_OrderAdapter.h
        ca_ingredientHandler.h
        fa_burger.h
        ad_RestaurantOrder.cpp
        ad_FloorOrder.cpp
        ad_OrderAdapter.cpp
        si_headChef.cpp
        fa_dish.cpp
        fa_Pizza.h
)

# Define sources for the tests
set(TEST_SOURCES
        kitchen/factory_unittest.cpp
        kitchen/headChef_unittest.cpp
        kitchen/headChefTest.cpp
        kitchen/factoryTest.cpp
        fa_dish.h
        ca_handler.h
        si_headChef.h
        fa_dishFactory.h
        fa_dishFactory.cpp
        ad_OrderAdapter.h
        ca_ingredientHandler.h
        fa_burger.h
        ad_RestaurantOrder.cpp
        ad_FloorOrder.cpp
        ad_OrderAdapter.cpp
        si_headChef.cpp
        fa_dish.cpp
        fa_Pizza.h
        test_main.cpp
)

# Define the main executable
add_executable(FlyweightFighters_COS214_Project ${PROJECT_SOURCES})

# Set up the linter
set(CMAKE_CXX_CLANG_TIDY clang-tidy)

# Define the test executable
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests gtest gtest_main pthread)

# Define the Valgrind test
add_test(
        NAME runTestsValgrind
        COMMAND valgrind --leak-check=full --error-exitcode=1 ./runTests
)
