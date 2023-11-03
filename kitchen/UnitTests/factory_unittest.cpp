#include <limits.h>
#include <stdexcept>
#include "factoryTest.h"
#include "gtest/gtest.h"

namespace
{
    TEST(IsFactoryTest, PositiveTesting)
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

    TEST(IsFactoryTest, TestPreconditionOneNegative)
    {
        std::string item = "VeganPizza";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella", testPizza(item, customizations));
    }
}