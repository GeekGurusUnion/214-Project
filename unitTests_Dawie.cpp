#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "fa_dishFactory.h"
#include "fa_Pizza.h"
#include "fa_burger.h"
#include "si_headChef.h"
#include "ad_RestaurantOrder.h"

std::string testPizza(const std::string &item, const std::vector<std::string> &customizations)
{
    ad_RestaurantOrder *order = new ad_RestaurantOrder(item, customizations);

    fa_pizzaFactory *factory = new fa_pizzaFactory();
    fa_dish *pizza = factory->createDish(*order);

    std::string result = pizza->getDescription();

    delete order;
    delete factory;
    delete pizza;

    return result;
}

std::string testBurger(const std::string &item, const std::vector<std::string> &customizations)
{
    ad_RestaurantOrder *order = new ad_RestaurantOrder(item, customizations);

    fa_burgerFactory *factory = new fa_burgerFactory();
    fa_dish *burger = factory->createDish(*order);

    std::string result = burger->getDescription();

    delete order;
    delete factory;
    delete burger;

    return result;
}

std::string testHeadChef(const std::string &item, const std::vector<std::string> &customizations)
{
    ad_RestaurantOrder *order = new ad_RestaurantOrder(item, customizations);

    si_headChef *chef = si_headChef::getInstance();

    fa_dish *dish = chef->prepareDish(*order);

    std::string result;

    if (dish != nullptr)
    {
        result = dish->getDescription();
    }
    else
    {
        result = "Dish unavailable.";
    }

    delete order;
    delete dish;

    return result;
}

si_headChef *testSingleton()
{
    return si_headChef::getInstance();
}

// Your test cases using Google Test
TEST(IsPizzaFactoryTest, PositiveTesting)
{
    std::string item = "BBQChickenPizza";
    std::vector<std::string> customizations = {""};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, BBQChicken, Bacon, Green Pepper", testPizza(item, customizations));

    item = "HawaiianPizza";
    customizations = {""};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pineapple, Ham", testPizza(item, customizations));

    item = "PepperoniPizza";
    customizations = {""};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pepperoni, Garlic", testPizza(item, customizations));
}

TEST(IsPizzaFactoryTest, TestPreconditionOneNegative)
{
    std::string item = "VeganPizza";
    std::vector<std::string> customizations = {""};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella", testPizza(item, customizations));
}

TEST(IsBurgerFactoryTest, PositiveTesting)
{
    std::string item = "DoubleBurger";
    std::vector<std::string> customizations = {""};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon, Beef Patty, Beef Patty", testBurger(item, customizations));

    item = "ChickenBurger";
    customizations = {""};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon, Chicken Breast, Pickle", testBurger(item, customizations));

    item = "BeefBurger";
    customizations = {""};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon, Beef Patty", testBurger(item, customizations));
}

TEST(IsBurgerFactoryTest, TestPreconditionOneNegative)
{
    std::string item = "ribBurger";
    std::vector<std::string> customizations = {""};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon", testBurger(item, customizations));
}

// Pizza Testing positive
TEST(IsHeadChefTest, PositiveTesting)
{
    std::string item = "BBQChickenPizza";
    std::vector<std::string> customizations = {"ExtraCheese"};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, BBQChicken, Bacon, Green Pepper, ExtraCheese", testHeadChef(item, customizations));

    item = "HawaiianPizza";
    customizations = {""};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pineapple, Ham", testHeadChef(item, customizations));

    item = "PepperoniPizza";
    customizations = {"ExtraCheese"};
    EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pepperoni, Garlic, ExtraCheese", testHeadChef(item, customizations));

    item = "DoubleBurger";
    customizations = {"NoCheese"};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Beef Patty, Beef Patty", testHeadChef(item, customizations));

    item = "ChickenBurger";
    customizations = {"ExtraCheese"};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon, Chicken Breast, Pickle, ExtraCheese", testHeadChef(item, customizations));

    item = "BeefBurger";
    customizations = {""};
    EXPECT_EQ("Burger with: buns, lettuce, mayo, Cheese, Bacon, Beef Patty", testHeadChef(item, customizations));
}

// headChef testing dish not available
TEST(IsHeadChefTest, TestPreconditionOneNegative)
{
    std::string item = "Steak";
    std::vector<std::string> customizations = {""};
    EXPECT_EQ("Dish unavailable.", testHeadChef(item, customizations));
}

TEST(IsHeadChefSingletonTest, TestPreconditionOneNegative)
{
    si_headChef *chef = si_headChef::getInstance();
    EXPECT_EQ(chef, testSingleton());

    chef = si_headChef::getInstance();
    EXPECT_EQ(chef, testSingleton());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}