cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_executable(FlyweightFighters_COS214_Project
        ../main.cpp
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
        fa_dish.cpp
        fa_Pizza.h
)
