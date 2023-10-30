cmake_minimum_required(VERSION 3.26)
project(FlyweightFighters_COS214_Project)

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_executable(FlyweightFighters_COS214_Project
        ../main.cpp
        dish.h
        order.h
        handler.h
        headChef.h
        dishFactory.h
        dishFactory.cpp
        adapter.h
        ingredientHandler.h)
