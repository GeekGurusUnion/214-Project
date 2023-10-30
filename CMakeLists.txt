cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_executable(FlyweightFighters_COS214_Project
        kitchen/main.cpp
        kitchen/dish.h
        kitchen/order.h
        kitchen/handler.h
        kitchen/headChef.h
        kitchen/dishFactory.h
        kitchen/dishFactory.cpp
        kitchen/adapter.h
        kitchen/ingredientHandler.h
        kitchen/burger.h
        kitchen/ingredientHandler.cpp
)
