#pragma once
#include "handler.h"
#include "burger.h"

class ingredientHandler : public handler {
protected:
    std::string ingredient;
public:
    ingredientHandler(const std::string& ingredient) : ingredient(ingredient) {}
    virtual ~ingredientHandler() {}

    virtual bool canHandle(const std::string& customization) = 0;
    virtual void handle(dish* d, const std::string& customization) = 0;
};

class AddingredientHandler : public ingredientHandler {
public:
    AddingredientHandler(const std::string& ingredient) : ingredientHandler(ingredient) {}

    bool canHandle(const std::string& customization) override {
        return customization == "Extra" + ingredient;
    }

    void handle(dish* d, const std::string& customization) override {
        if(canHandle(customization)) {
           d->addComponent(customization);
        }
        if(nextHandler) nextHandler->handle(d, customization);
    }
};

class RemoveingredientHandler : public ingredientHandler {
public:
    RemoveingredientHandler(const std::string& ingredient) : ingredientHandler(ingredient) {}

    bool canHandle(const std::string& customization) override {
        return customization == "No" + ingredient;
    }

    void handle(dish* d, const std::string& customization) override {
        if(canHandle(customization)) {
            d->removeComponent(customization);
        }
        if(nextHandler) nextHandler->handle(d, customization);
    }
};
