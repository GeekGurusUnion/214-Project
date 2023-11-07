/* ca_handler.h */

/**
 * @file ca_handler.h
 * @brief Defines the interface for a handler in the Chain of Responsibility pattern.
 */

#pragma once
#include "fa_dish.h"

/**
 * @class ca_handler
 * @brief Interface for a handler in the Chain of Responsibility pattern.
 * 
 * The ca_handler class is the interface for a handler in the Chain of Responsibility pattern.
 * It defines the interface for handling a customization of a dish.
 */

class ca_handler {
public:
    ca_handler* nextHandler;  ///< Pointer to the next handler in the chain.

    /**
     * @brief Constructs a handler object.
     */
    ca_handler() : nextHandler(nullptr) {}

    /**
     * @brief Destructor for the handler object.
     */
    virtual ~ca_handler() {delete nextHandler;}

    /**
     * @brief Sets the next handler in the chain.
     * @param next Pointer to the next handler object.
     */
    void setNextHandler(ca_handler* next) {
        nextHandler = next;
    }

    /**
     * @brief Checks if the handler can handle a specific customization.
     * @param customization The customization to check.
     * @return true if the handler can handle the customization, false otherwise.
     */
    virtual bool canHandle(const std::string& customization) = 0;

    /**
     * @brief Handles the customization of a dish.
     * @param dish Pointer to the dish to be customized.
     * @param customization The customization to be applied.
     */
    virtual void handle(fa_dish* dish, const std::string& customization) = 0;
};
