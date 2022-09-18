//
// Created by daniil on 17.09.22.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Vector.h"

TEST(vector_test, vector_creation) {
    Vector vector1{1, 3, 5, 7};

    Vector vector2(10);
    vector2 = vector1;
    vector2[2] = 10;

    ASSERT_EQ(vector1[2], 5);
    ASSERT_EQ(vector2[2], 10);
}

namespace {
    class VectorTest : public testing::Test {
    public:
        Vector *vector;
    protected:
        void SetUp() override {
            vector = new Vector(10);
        }

        void TearDown() override {
            delete vector;
        }
    };
}

TEST_F(VectorTest, vector_copy_constructor_test) {
    ASSERT_EQ(vector->size(), 10);
}

TEST_F(VectorTest, vector_copy_constructor_test_bad) {
    ASSERT_EQ(vector->size(), 11);
}

