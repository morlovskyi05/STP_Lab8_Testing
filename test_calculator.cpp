#include "Calculator.h"
#include <gtest/gtest.h>
#include <vector>

// ========== ТЕСТИ ДЛЯ findMinPositive ==========

// Позитивні тести
TEST(FindMinPositiveTest, PositiveTest_StandardArray) {
    std::vector<double> arr = {5.5, 2.3, 8.1, 1.7, 4.2};
    EXPECT_DOUBLE_EQ(Calculator::findMinPositive(arr), 1.7);
}

TEST(FindMinPositiveTest, PositiveTest_SingleElement) {
    std::vector<double> arr = {42.0};
    EXPECT_DOUBLE_EQ(Calculator::findMinPositive(arr), 42.0);
}

TEST(FindMinPositiveTest, PositiveTest_AllSameValues) {
    std::vector<double> arr = {7.0, 7.0, 7.0, 7.0};
    EXPECT_DOUBLE_EQ(Calculator::findMinPositive(arr), 7.0);
}

// Негативні тести
TEST(FindMinPositiveTest, NegativeTest_EmptyArray) {
    std::vector<double> arr = {};
    EXPECT_THROW(Calculator::findMinPositive(arr), std::invalid_argument);
}

TEST(FindMinPositiveTest, NegativeTest_ContainsZero) {
    std::vector<double> arr = {5.0, 0.0, 3.0};
    EXPECT_THROW(Calculator::findMinPositive(arr), std::invalid_argument);
}

TEST(FindMinPositiveTest, NegativeTest_ContainsNegative) {
    std::vector<double> arr = {5.0, -2.0, 3.0};
    EXPECT_THROW(Calculator::findMinPositive(arr), std::invalid_argument);
}

// ========== ТЕСТИ ДЛЯ sumNegative ==========

// Позитивні тести
TEST(SumNegativeTest, PositiveTest_StandardArray) {
    std::vector<double> arr = {-1.5, -2.5, -3.0, -4.0};
    EXPECT_DOUBLE_EQ(Calculator::sumNegative(arr), -11.0);
}

TEST(SumNegativeTest, PositiveTest_SingleElement) {
    std::vector<double> arr = {-10.5};
    EXPECT_DOUBLE_EQ(Calculator::sumNegative(arr), -10.5);
}

TEST(SumNegativeTest, PositiveTest_LargeNegatives) {
    std::vector<double> arr = {-100.0, -200.0, -50.5};
    EXPECT_DOUBLE_EQ(Calculator::sumNegative(arr), -350.5);
}

// Негативні тести
TEST(SumNegativeTest, NegativeTest_EmptyArray) {
    std::vector<double> arr = {};
    EXPECT_THROW(Calculator::sumNegative(arr), std::invalid_argument);
}

TEST(SumNegativeTest, NegativeTest_ContainsZero) {
    std::vector<double> arr = {-5.0, 0.0, -3.0};
    EXPECT_THROW(Calculator::sumNegative(arr), std::invalid_argument);
}

TEST(SumNegativeTest, NegativeTest_ContainsPositive) {
    std::vector<double> arr = {-5.0, 2.0, -3.0};
    EXPECT_THROW(Calculator::sumNegative(arr), std::invalid_argument);
}

// ========== ТЕСТИ ДЛЯ fibonacci ==========

// Позитивні тести
TEST(FibonacciTest, PositiveTest_Zero) {
    EXPECT_EQ(Calculator::fibonacci(0), 0);
}

TEST(FibonacciTest, PositiveTest_One) {
    EXPECT_EQ(Calculator::fibonacci(1), 1);
}

TEST(FibonacciTest, PositiveTest_StandardValues) {
    EXPECT_EQ(Calculator::fibonacci(5), 5);
    EXPECT_EQ(Calculator::fibonacci(10), 55);
    EXPECT_EQ(Calculator::fibonacci(15), 610);
}

TEST(FibonacciTest, PositiveTest_LargeValue) {
    EXPECT_EQ(Calculator::fibonacci(20), 6765);
}

// Негативні тести
TEST(FibonacciTest, NegativeTest_NegativeNumber) {
    EXPECT_THROW(Calculator::fibonacci(-1), std::invalid_argument);
}

TEST(FibonacciTest, NegativeTest_NegativeLargeNumber) {
    EXPECT_THROW(Calculator::fibonacci(-100), std::invalid_argument);
}

// ========== ТЕСТИ ДЛЯ calculateCurrent ==========

// Позитивні тести
TEST(CalculateCurrentTest, PositiveTest_StandardValues) {
    EXPECT_DOUBLE_EQ(Calculator::calculateCurrent(220.0, 10.0), 22.0);
}

TEST(CalculateCurrentTest, PositiveTest_SmallVoltage) {
    EXPECT_DOUBLE_EQ(Calculator::calculateCurrent(5.0, 2.5), 2.0);
}

TEST(CalculateCurrentTest, PositiveTest_HighResistance) {
    EXPECT_NEAR(Calculator::calculateCurrent(100.0, 1000.0), 0.1, 0.001);
}

TEST(CalculateCurrentTest, PositiveTest_ZeroVoltage) {
    EXPECT_DOUBLE_EQ(Calculator::calculateCurrent(0.0, 10.0), 0.0);
}

// Негативні тести
TEST(CalculateCurrentTest, NegativeTest_ZeroResistance) {
    EXPECT_THROW(Calculator::calculateCurrent(220.0, 0.0), std::invalid_argument);
}

TEST(CalculateCurrentTest, NegativeTest_NegativeResistance) {
    EXPECT_THROW(Calculator::calculateCurrent(220.0, -10.0), std::invalid_argument);
}

// Головна функція для запуску тестів
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}