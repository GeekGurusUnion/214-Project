#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ad_OrderAdapter.h"
#include "fa_dish.h"


std::vector<std::string> testAdapter(const std::vector<std::string> &customizations) {

    ad_OrderAdapter *adapt = new ad_OrderAdapter(customizations);
    std::vector<std::string> out = adapt->getDetails();
    delete adapt;
    return out;

}

std::vector<std::string> testRest(const std::string &item, const std::vector<std::string> &customizations) {

    ad_RestaurantOrder *adapt = new ad_RestaurantOrder(item, customizations);
    std::vector<std::string> out = adapt->getCustomizations();
    std::string out2 = adapt->getItem();
    delete adapt;
    out.push_back(out2);
    return out;

}

std::string testOrder(const std::vector<std::string> &customizations) {
    ad_OrderAdapter *adapt = new ad_OrderAdapter(customizations);
    fa_dish *ad = adapt->PlaceOrder();
    std::string out = ad->getDescription();
    delete adapt;
    delete ad;
    return out;
}

// Your test cases using Google Test
TEST(IsAdapter, PositiveTesting
)
{
std::vector<std::string> customizations = {"BBQChickenPizza"};
EXPECT_EQ(std::vector<std::string>{"BBQChickenPizza"}, testAdapter(customizations)
);

}
TEST(IsRestauranTest, PositiveTesting
)
{
std::vector<std::string> customizations = {"NoBacon"};
std::string it = "BBQChickenPizza";
std::vector<std::string> out = {"NoBacon", "BBQChickenPizza"};
EXPECT_EQ(out, testRest(it, customizations)
);

customizations = {};
it = "BBQChickenPizza";
out = {"BBQChickenPizza"};
EXPECT_EQ(out, testRest(it, customizations)
);

}

TEST(IsFullTest, PositiveTesting
)
{
std::vector<std::string> customizations = {"BBQChickenPizza", "NoBacon", "ExtraCheese"};
EXPECT_EQ("Pizza with: Base, Tomato Sauce, Mozzarella, BBQChicken, Green Pepper, ExtraCheese",
testOrder(customizations)
);

customizations = {"ChickenBurger", "NoPickles", "NoCheese", "NoBacon"};
EXPECT_EQ("Burger with: buns, lettuce, mayo, Chicken Breast",
testOrder(customizations)
);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}