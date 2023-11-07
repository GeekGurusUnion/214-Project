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

# Define sources for the main project
set(PROJECT_SOURCES
        main.cpp
        ad_FloorOrder.h
        ad_FloorOrder.cpp
        ad_OrderAdapter.h
        ad_OrderAdapter.cpp
        ad_RestaurantOrder.h
        ad_RestaurantOrder.cpp
        ca_handler.h
        ca_ingredientHandler.h
        Colleague.cpp
        Colleague.h
        Command.h
        Complaints.h
        Complaints.cpp
        ConcreteMediator.h
        ConcreteMediator.cpp
        ConfirmOrder.h
        ConfirmOrder.cpp
        CustomizeOrder.h
        CustomizeOrder.cpp
        fa_burger.h
        fa_dish.h
        fa_dish.cpp
        fa_dishFactory.h
        fa_dishFactory.cpp
        fa_Pizza.h
        Facade.cpp
        Facade.h
        FloorColleague.cpp
        FloorColleague.h
        GenerateBill.cpp
        GenerateBill.h
        Iterator.h
        KitchenColleague.h
        KitchenColleague.cpp
        Mediator.cpp
        Mediator.h
        MenuItem.cpp
        MenuItem.h
        MergeTables.cpp
        MergeTables.h
        Order.cpp
        Order.h
        RestaurantTable.cpp
        RestaurantTable.h
        ServeOrder.cpp
        ServeOrder.h
        si_headChef.cpp
        si_headChef.h
        SplitBill.cpp
        SplitBill.h
        State.cpp
        State.h
        StateEmpty.h
        StateEmpty.cpp
        StateOccupied.h
        StateOccupied.cpp
        StateServe.cpp
        StateServe.h
        TableIterator.cpp
        TableIterator.h
        TableObserver.cpp
        TableObserver.h
        TakeOrder.cpp
        TakeOrder.h
        TipOrder.cpp
        TipOrder.h
        Waiter.cpp
        Waiter.h
        WaiterIterator.cpp
        WaiterIterator.h
        WaiterState.cpp
        WaiterState.h
        WaiterStateAvailable.h
        WaiterStateAvailable.cpp
        WaiterStateUnavailable.cpp
        WaiterStateUnavailable.h

)

# Define sources for the tests
set(TEST_SOURCES
        unitTests_Dawie.cpp
        ad_FloorOrder.h
        ad_FloorOrder.cpp
        ad_OrderAdapter.h
        ad_OrderAdapter.cpp
        ad_RestaurantOrder.h
        ad_RestaurantOrder.cpp
        ca_handler.h
        ca_ingredientHandler.h
        Colleague.cpp
        Colleague.h
        Command.h
        Complaints.h
        Complaints.cpp
        ConcreteMediator.h
        ConcreteMediator.cpp
        ConfirmOrder.h
        ConfirmOrder.cpp
        CustomizeOrder.h
        CustomizeOrder.cpp
        fa_burger.h
        fa_dish.h
        fa_dish.cpp
        fa_dishFactory.h
        fa_dishFactory.cpp
        fa_Pizza.h
        Facade.cpp
        Facade.h
        FloorColleague.cpp
        FloorColleague.h
        GenerateBill.cpp
        GenerateBill.h
        Iterator.h
        KitchenColleague.h
        KitchenColleague.cpp
        Mediator.cpp
        Mediator.h
        MenuItem.cpp
        MenuItem.h
        MergeTables.cpp
        MergeTables.h
        Order.cpp
        Order.h
        RestaurantTable.cpp
        RestaurantTable.h
        ServeOrder.cpp
        ServeOrder.h
        si_headChef.cpp
        si_headChef.h
        SplitBill.cpp
        SplitBill.h
        State.cpp
        State.h
        StateEmpty.h
        StateEmpty.cpp
        StateOccupied.h
        StateOccupied.cpp
        StateServe.cpp
        StateServe.h
        TableIterator.cpp
        TableIterator.h
        TableObserver.cpp
        TableObserver.h
        TakeOrder.cpp
        TakeOrder.h
        TipOrder.cpp
        TipOrder.h
        Waiter.cpp
        Waiter.h
        WaiterIterator.cpp
        WaiterIterator.h
        WaiterState.cpp
        WaiterState.h
        WaiterStateAvailable.h
        WaiterStateAvailable.cpp
        WaiterStateUnavailable.cpp
        WaiterStateUnavailable.h
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
