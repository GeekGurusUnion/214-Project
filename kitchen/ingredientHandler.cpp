#include "ingredientHandler.h"

void AddIngredientHandler::handle(dish* dish) {
    burger* Burger = dynamic_cast<burger*>(dish);
    if (Burger) {
        Burger->addComponent(ingredient);
    }
    if (nextHandler) nextHandler->handle(dish);
}

void RemoveIngredientHandler::handle(dish* dish) {
    burger* Burger = dynamic_cast<burger*>(dish);
    if (Burger) {
        Burger->removeComponent(ingredient);
    }
    if (nextHandler) nextHandler->handle(dish);
}
