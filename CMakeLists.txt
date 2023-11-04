cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_executable(FlyweightFighters_COS214_Project
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
        kitchen/fa_dish.cpp
        kitchen/fa_Pizza.h
)
