<<<<<<< HEAD
#include <limits.h>
#include <stdexcept>
#include "factoryTest.h"
#include "gtest/gtest.h"

namespace
{
    //Pizza Testing positive
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

    //Pizza testing pizza not available
    TEST(IsPizzaFactoryTest, TestPreconditionOneNegative)
    {
        std::string item = "VeganPizza";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella", testPizza(item, customizations));
    }

    //Burger testing positive
    TEST(IsBurgerFactoryTest, PositiveTesting)
    {
        std::string item = "DoubleBurger";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty, Beef Patty", testBurger(item, customizations));

        item = "ChickenBurger";
        customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Chicken Breast, Pickle", testBurger(item, customizations));

        item = "BeefBurger";
        customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty", testBurger(item, customizations));
    }

    // Burger testing burger not available
    TEST(IsBurgerFactoryTest, TestPreconditionOneNegative)
    {
        std::string item = "ribBurger";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon", testBurger(item, customizations));
    }
=======
#include <limits.h>
#include <stdexcept>
#include "factoryTest.h"
#include "gtest/gtest.h"

namespace
{
    //Pizza Testing positive
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

    //Pizza testing pizza not available
    TEST(IsPizzaFactoryTest, TestPreconditionOneNegative)
    {
        std::string item = "VeganPizza";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella", testPizza(item, customizations));
    }

    //Burger testing positive
    TEST(IsBurgerFactoryTest, PositiveTesting)
    {
        std::string item = "DoubleBurger";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty, Beef Patty", testBurger(item, customizations));

        item = "ChickenBurger";
        customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Chicken Breast, Pickle", testBurger(item, customizations));

        item = "BeefBurger";
        customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon, Beef Patty", testBurger(item, customizations));
    }

    // Burger testing burger not available
    TEST(IsBurgerFactoryTest, TestPreconditionOneNegative)
    {
        std::string item = "ribBurger";
        std::vector<std::string> customizations = {""};
        EXPECT_EQ("Burger with: buns, lettuce, mayo, cheese, bacon", testBurger(item, customizations));
    }
>>>>>>> 7445f2bc56b97a1dd23166483edccaa3f44c8ce9
}