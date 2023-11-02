/**
 * @file fa_dish.h
 * @brief Defines the abstract class representing a dish in a restaurant system.
 *
 * This abstract class provides a common interface and operations for different types of dishes.
 */
#pragma once

#include <string>
#include <vector>
#include <algorithm>
/**
 * @class fa_dish
 * @brief Abstract class representing a dish with customizable components.
 *
 * This class defines the basic operations like adding and removing components for a dish.
 */
class fa_dish {
protected:
    std::vector<std::string> components;///< List of components in the dish.

public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~fa_dish() = default;
    /**
    * @brief Pure virtual function to get the description of the dish.
    *
    * This function is intended to be overridden by derived classes to provide
    * a detailed description of the dish including its components.
    *
    * @return A string representing the description of the dish.
    */
    virtual std::string getDescription() const = 0;
    /**
     * @brief Adds a component to the dish.
     *
     * This function adds a given component to the list of components for this dish.
     *
     * @param component A string representing the component to be added.
     */
    void addComponent(const std::string &component) ;

    /**
     * @brief Removes a component from the dish.
     *
     * This function removes a given component from the list of components for this dish.
     *
     * @param component A string representing the component to be removed.
     */
    void removeComponent(const std::string &component) ;
};
