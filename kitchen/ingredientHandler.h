#pragma once
#include "handler.h"
#include "Burger.h"

class AddIngredientHandler : public handler {
private:
    std::string ingredient;

public:
    AddIngredientHandler(const std::string& ingredient) : ingredient(ingredient) {}

    void handle(dish* dish) override;

};

class RemoveIngredientHandler : public handler {
private:
    std::string ingredient;

public:
    RemoveIngredientHandler(const std::string& ingredient) : ingredient(ingredient) {}

    void handle(dish* dish) override;

};
