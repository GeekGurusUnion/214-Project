#include "si_headChef.h"
#include "ad_RestaurantOrder.h"
#include "fa_dishFactory.h"
#include "ca_ingredientHandler.h"

si_headChef *si_headChef::instance = nullptr;

si_headChef *si_headChef::getInstance() {
    if (!instance) {
        instance = new si_headChef();
    }
    return instance;
}

si_headChef::si_headChef() : startOfChain(createHandlerChain()) {}

void si_headChef::destroyInstance() {
    delete instance;
    instance = nullptr;
}

ca_handler *si_headChef::createHandlerChain() {
    ca_handler *start = new AddingredientHandler("Cheese");
    ca_handler *current = start;

    ca_handler *next = new RemoveingredientHandler("Onion");
    current->setNextHandler(next);
    current = next;

    next = new AddingredientHandler("Tomato");
    current->setNextHandler(next);
    current = next;

    return start;
}

fa_dish *si_headChef::prepareDish(const ad_RestaurantOrder &order) {
    fa_dish *createdDish = nullptr;
    fa_dishFactory *factory = nullptr;

    if (order.getItem().find("Burger") != std::string::npos) {
        factory = new fa_burgerFactory();
    } else if (order.getItem().find("Pizza") != std::string::npos) {
        factory = new fa_pizzaFactory();
    }
    // else{
    //     createdDish = new fa_emptyDish({""});
    //     return createdDish;
    // }

    if (factory) {
        createdDish = factory->createDish(order);
        for (const auto &customization: order.getCustomizations()) {
            startOfChain->handle(createdDish, customization);
        }

        delete factory;
    }

    return createdDish;
}


si_headChef::~si_headChef() {
    ca_handler *current = startOfChain;
    while (current) {
        ca_handler *toDelete = current;
        current = current->nextHandler;
        delete toDelete;
    }
}
