#pragma once
#include "dish.h"

class handler {
protected:
    handler* nextHandler;

public:
    handler() : nextHandler(nullptr) {}
    virtual ~handler() {}

    void setNextHandler(handler* next) {
        nextHandler = next;
    }

    virtual void handle(dish* dish) = 0;
};
