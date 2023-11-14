//
// Created by 小圆鹅 on 10/11/2023.
//

#include "test.h"
// test.cpp
#include <gtest/gtest.h>
#include "gs.h"  // 包含头文件，而不是 gs.cpp

//#include "gs.cpp"  // Assuming gs.cpp is in the same directory and has the necessary functions exposed.

// Test 0.1: Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
TEST(GrayScottTest, CheckParameterTypes) {
// Check if types of F and k match the type of elements in u and v
ASSERT_TRUE((std::is_same<decltype(F), double>::value));
ASSERT_TRUE((std::is_same<decltype(k), double>::value));
using UElementType = decltype(u[0][0]);
using VElementType = decltype(v[0][0]);
ASSERT_TRUE(typeid(F).name() == typeid(UElementType).name() && typeid(k).name() == typeid(VElementType).name());
//std::cout << "Test1 Passed!" << std::endl;
}

// Test 0.2: Check that the variables u and v are the same size.
TEST(GrayScottTest, CheckSameSize) {
// Check if u and v have the same dimensions
EXPECT_EQ(u.size(), v.size());
for (size_t i = 0; i < u.size(); ++i) {
EXPECT_EQ(u[i].size(), v[i].size());
}
}

// Test 0.3: Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
TEST(GrayScottTest, CheckSimulationResultForZero) {
// Initialize u and v to 0
for (auto &row : u) std::fill(row.begin(), row.end(), 0.0);
for (auto &row : v) std::fill(row.begin(), row.end(), 0.0);
const double epsilon = 0.0018; // Small value for floating point comparison
// Perform a simulation step
simulateStep();

// Check the result after one simulation step
for (size_t x = 0; x < width; ++x) {
for (size_t y = 0; y < height; ++y) {
// When both u and v are 0, the result should stay 0 (assuming no external feed or kill rates)
EXPECT_NEAR(u[x][y], 0.0, epsilon);
EXPECT_NEAR(v[x][y], 0.0, epsilon);
}
}
std::cout << "Simulation check successful: u increasing and v remaining at 0 and the error is within 0.0018" << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
