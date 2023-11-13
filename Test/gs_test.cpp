//
// Created by CAI GAO on 2023/11/12.
//
#include <gtest/gtest.h>
#include "gs.h"
TEST(Test, ElementType){
    EXPECT_EQ(typeid(F), typeid(double));
    EXPECT_EQ(typeid(k), typeid(double));
}
TEST(Test, ElementSize){
//row_check
    EXPECT_EQ(u.size(), v.size());
//col_check
    for (size_t i = 0; i < u.size(); ++i) {
    EXPECT_EQ(u[i].size(), v[i].size());
    }
}
