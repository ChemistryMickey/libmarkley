#include "gtest/gtest.h"
#include "math/LinfNorm.hpp"
#include <eigen3/Eigen/Dense>

using namespace markley;

TEST(TestLinfNorm, Empty) {
    Eigen::Vector<double, 10> v{};
    EXPECT_EQ(l_infinity_norm<10>(v), 0);
}

TEST(TestLinfNorm, ZeroSize) {
    Eigen::Vector<double, 0> v{};
    EXPECT_EQ(l_infinity_norm<0>(v), 0);
}

TEST(TestLinfNorm, MonotonicallyIncreasing) {
    Eigen::Vector<double, 10> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(l_infinity_norm<10>(v), 9);
}

TEST(TestLinfNorm, WithNegatives) {
    Eigen::Vector<double, 10> v{0, 1, 2, 3, -10, 5, 6, 7, 8, 9};
    EXPECT_EQ(l_infinity_norm<10>(v), 10);
}

TEST(TestLinfNorm, Integers) {
    Eigen::Vector<int, 10> v{0, 1, 2, 3, -10, 5, 6, 7, 8, 9};
    EXPECT_EQ(l_infinity_norm<10>(v), 10);
}

TEST(TestLinfNorm, Integers64bit) {
    Eigen::Vector<int64_t, 10> v{0, 1, 2, 3, -10, 5, 6, 7, 8, 9};
    EXPECT_EQ(l_infinity_norm<10>(v), 10);
}

TEST(TestLinfNorm, UnsignedIntegers) {
    Eigen::Vector<uint64_t, 10> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(l_infinity_norm<10>(v), 9);
}

