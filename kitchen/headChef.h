#pragma once

#include "dishFactory.h"
#include "handler.h"
#include "ingredientHandler.h"

class headChef {
private:
    handler *startOfChain;

public:

    headChef() : startOfChain(nullptr) {
        startOfChain = createHandlerChain();
    }

    handler *createHandlerChain() {
        handler *start = new AddingredientHandler("Cheese");
        handler *current = start;

        handler *next = new RemoveingredientHandler("Onion");
        current->setNextHandler(next);
        current = next;


        next = new AddingredientHandler("Tomato");
        current->setNextHandler(next);
        current = next;

        return start;
    }


    dish *prepareDish(const KitchenOrder &order) {
        dish *createdDish;
        if (order.getItem() == "Burger") {
            burgerFactory burgerFactoryInstance;
            createdDish = burgerFactoryInstance.createDish(order);
        } else {
            createdDish = nullptr;
        }

        for (const auto &customization: order.getCustomizations()) {
            startOfChain->handle(createdDish, customization);
        }

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
