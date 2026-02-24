#include "gtest/gtest.h"
#include "math/norms.hpp"
#include <eigen3/Eigen/Dense>

using namespace markley;

// $L_{\infty}$
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

// L2
TEST(TestL2Norm, Empty) {
    Eigen::Vector<double, 10> v{};
    EXPECT_EQ(l_2_norm<10>(v), 0);
}

TEST(TestL2Norm, ZeroSize) {
    Eigen::Vector<double, 0> v{};
    EXPECT_EQ(l_2_norm<0>(v), 0);
}

TEST(TestL2Norm, MonotonicallyIncreasing) {
    Eigen::Vector<double, 3> v{1, 2, 3};
    EXPECT_EQ(l_2_norm<3>(v), 14);
}

TEST(TestL2Norm, WithNegatives) {
    Eigen::Vector<double, 3> v{1, -2, -3};
    EXPECT_EQ(l_2_norm<3>(v), 14);
}

TEST(TestL2Norm, Integers64bit) {
    Eigen::Vector<int64_t, 4> v{1, 2, 3, -10};
    EXPECT_EQ(l_2_norm<4>(v), 114);
}

TEST(TestL2Norm, UnsignedIntegers) {
    Eigen::Vector<uint64_t, 4> v{0, 1, 2, 3};
    EXPECT_EQ(l_2_norm<4>(v), 14);
}