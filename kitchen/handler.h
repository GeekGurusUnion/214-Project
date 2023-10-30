#pragma once
#include "dish.h"

class handler {
public:
    handler* nextHandler;

    handler() : nextHandler(nullptr) {}
    virtual ~handler() {}

    void setNextHandler(handler* next) {
        nextHandler = next;
    }

    virtual bool canHandle(const std::string& customization) = 0;
    virtual void handle(dish* dish, const std::string& customization) = 0;
};
