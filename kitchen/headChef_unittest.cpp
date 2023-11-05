#include <limits.h>
#include <stdexcept>
#include "headChefTest.h"
#include "gtest/gtest.h"

namespace
{
    //Pizza Testing positive
    TEST(IsHeadChefTest, PositiveTesting)
    {
        std::string item = "BBQChickenPizza";
        std::vector<std::string> customizations = {"ExtraCheese"};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, BBQChicken, Bacon, Green Pepper, ExtraCheese", testHeadChef(item, customizations));

        item = "HawaiianPizza";
        customizations = {""};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pineapple, Ham", testHeadChef(item, customizations));

        item = "PepperoniPizza";
        customizations = {"ExtraTomato", "ExtraCheese"};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, Pepperoni, Garlic, ExtraTomato, ExtraCheese", testHeadChef(item, customizations));

        item = "DoubleBurger";
        customizations = {"ExtraTomato"};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty, Beef Patty, ExtraTomato", testHeadChef(item, customizations));

        item = "ChickenBurger";
        customizations = {"ExtraTomato", "ExtraCheese"};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Chicken Breast, Pickle, ExtraTomato, ExtraCheese", testHeadChef(item, customizations));

        item = "BeefBurger";
        customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty", testHeadChef(item, customizations));
    }

    //headChef testing dish not available
    TEST(IsHeadChefTest, TestPreconditionOneNegative)
    {
        std::string item = "Steak";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Dish unavailable.", testHeadChef(item, customizations));
    }

    TEST(IsHeadChefSingletonTest, TestPreconditionOneNegative)
    {
        si_headChef* chef = si_headChef::getInstance();
        EXPECT_EQ(chef, testSingleton());

        chef = si_headChef::getInstance();
        EXPECT_EQ(chef, testSingleton());
    }
}