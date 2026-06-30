//
// Created by Kacper Zięba on 30/06/2026.
//

#include <gtest/gtest.h>
#include <Activation.h>

TEST(ActivationTest, sigmoidValues) {
    EXPECT_DOUBLE_EQ(Activations::sigmoid(0.0), 0.5);
    EXPECT_NEAR(Activations::sigmoid(100.0), 1.0, 1e-9);
    EXPECT_NEAR(Activations::sigmoid(-100.0), 0.0, 1e-9);
}

TEST(ActivationTest, ReluValues) {
    EXPECT_DOUBLE_EQ(Activations::relu(0.0), 0.0);
    EXPECT_DOUBLE_EQ(Activations::relu(-5.5), 0.0);
    EXPECT_DOUBLE_EQ(Activations::relu(5.5), 5.5);
}