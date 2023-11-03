#include <gtest/gtest.h>

// Define a test suite and a test case using the TEST macro
TEST(HelloTest, BasicAssertions) {
    // Your test logic goes here
    ASSERT_EQ(1, 1); // Example assertion
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
