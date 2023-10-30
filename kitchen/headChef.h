#pragma once

#include "dishFactory.h"
#include "handler.h"
#include "ingredientHandler.h"

class headChef {
private:
    handler *startOfChain;

public:

    headChef() : startOfChain(nullptr) {
        startOfChain = new RemoveIngredientHandler("onion");
        handler *nextHandler = new AddIngredientHandler("cheese");
        startOfChain->setNextHandler(nextHandler);
    }

    dish *prepareDish(const KitchenOrder &order) {
        dish *createdDish;
        if (order.getItem() == "Burger") {
            burgerFactory burgerFactoryInstance;
            createdDish = burgerFactoryInstance.createDish(order);
        } else {
            createdDish = nullptr;
        }
        startOfChain->handle(createdDish);
        return createdDish;
    }

    ~headChef() {
        handler *current = startOfChain;
        while (current) {
            handler *toDelete = current;
            current = current->nextHandler;
            delete toDelete;
        }
    }
};
