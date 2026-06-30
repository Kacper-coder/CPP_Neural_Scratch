//
// Created by Kacper Zięba on 29/06/2026.
//

#include <gtest/gtest.h>
#include <stdexcept>

#include "Activation.h"
#include "Matrix.h"

TEST(MatrixTest, Initialization) {
    Matrix m(3, 2);

    EXPECT_EQ(m.getNumRows(), 3);
    EXPECT_EQ(m.getNumCols(), 2);
    EXPECT_DOUBLE_EQ(m(0, 0), 0.0);
    EXPECT_DOUBLE_EQ(m(2, 1), 0.0);
}

TEST(MatrixTest, getNumRowsColsDataTest) {
    Matrix m(3, 2);
    EXPECT_EQ(m.getNumRows(), 3);
    EXPECT_EQ(m.getNumCols(), 2);

    std::vector<double> vec = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    EXPECT_EQ(m.getData(), vec);
}

TEST(MatrixTest, ElementAccess) {
    Matrix m(2, 2);
    m(0, 0) = 1.5;
    m(0, 1) = 2.9;

    EXPECT_DOUBLE_EQ(m(0, 0), 1.5);
    EXPECT_DOUBLE_EQ(m(0, 1), 2.9);
}

TEST(MatrixTest, Addition) {
    Matrix m(2, 2);
    m(0, 0) = 1.5; m(0, 1) = 2.9;
    m(1, 0) = 1.5; m(1, 1) = 2.9;

    Matrix expected(2, 2);
    expected(0, 0) = 3.0; expected(0, 1) = 5.8;
    expected(1, 0) = 3.0; expected(1, 1) = 5.8;

    EXPECT_EQ(m + m, expected);
}

TEST(MatrixTest, Subtraction) {
    Matrix m(2, 2);
    m(0, 0) = 1.5; m(0, 1) = 2.9;
    m(1, 0) = 1.5; m(1, 1) = 2.9;

    Matrix expected(2, 2);
    // Domyślnie nowa macierz jest wypełniona zerami, więc nie musimy jej ręcznie ustawiać na 0.0!

    EXPECT_EQ(m - m, expected);
}

TEST(MatrixTest, Multiplication) {
    Matrix m1(2, 2);
    m1(0, 0) = 1.0; m1(0, 1) = 2.0;
    m1(1, 0) = 3.0; m1(1, 1) = 4.0;

    Matrix m2(2, 2);
    m2(0, 0) = 4.0; m2(0, 1) = 3.0;
    m2(1, 0) = 2.0; m2(1, 1) = 1.0;

    Matrix expected(2, 2);
    expected(0, 0) = 8.0;  expected(0, 1) = 5.0;
    expected(1, 0) = 20.0; expected(1, 1) = 13.0;

    EXPECT_EQ(m1 * m2, expected);
}

TEST(MatrixTest, ScalarMultiplication) {
    Matrix m(2, 2);
    m(0, 0) = 1.0; m(0, 1) = 2.0;
    m(1, 0) = 1.0; m(1, 1) = 2.0;

    Matrix expected(2, 2);
    expected(0, 0) = 5.0; expected(0, 1) = 10.0;
    expected(1, 0) = 5.0; expected(1, 1) = 10.0;

    EXPECT_EQ(m * 5.0, expected);
}

TEST(MatrixTest, Transpose) {
    Matrix m(2, 2);
    m(0, 0) = 1.0; m(0, 1) = 2.0;
    m(1, 0) = 3.0; m(1, 1) = 4.0;

    Matrix expected(2, 2);
    expected(0, 0) = 1.0; expected(0, 1) = 3.0;
    expected(1, 0) = 2.0; expected(1, 1) = 4.0;

    EXPECT_EQ(m.transpose(), expected);
}

TEST(MatrixTest, Hadamard) {
    Matrix m(2, 2);
    m(0, 0) = 1.0; m(0, 1) = 2.0;
    m(1, 0) = 3.0; m(1, 1) = 4.0;

    Matrix m2(2, 2);
    m2(0, 0) = 2.0; m2(0, 1) = 2.0;
    m2(1, 0) = 2.0; m2(1, 1) = 2.0;

    // Sprytne wykorzystanie wcześniej przetestowanego mnożenia skalarnego do wygenerowania oczekiwanego wyniku!
    Matrix expected = m * 2.0;

    EXPECT_EQ(m.hadamard(m2), expected);
}

// --- NOWY TEST: Sprawdzanie czy nasz kod dobrze reaguje na błędy ---
TEST(MatrixTest, ThrowsOnInvalidDimensions) {
    Matrix m1(2, 3);
    Matrix m2(4, 5);

    // EXPECT_THROW sprawdza, czy po wykonaniu (m1 + m2) wyleci wyjatek typu std::invalid_argument
    EXPECT_THROW(m1 + m2, std::invalid_argument);
    EXPECT_THROW(m1 - m2, std::invalid_argument);
    EXPECT_THROW(m1 * m2, std::invalid_argument); // Mnożenie 2x3 przez 4x5 jest nielegalne
    EXPECT_THROW(m1.hadamard(m2), std::invalid_argument);
}

TEST(MatrixTest, MapFunctionSigmoid) {
    Matrix m(2, 2);
    m(0, 0) = 0.0; m(0, 1) = 1000.;
    m(1, 0) = -1000.; m(1, 1) = 0.0;

    Matrix expected(2, 2);
    expected(0, 0) = 0.5; expected(0, 1) = 1.;
    expected(1, 0) = 0.; expected(1, 1) = 0.5;

    EXPECT_EQ(m.map(Activations::sigmoid), expected);
}

TEST(MatrixTest, MapFunctionRelu) {
    Matrix m(2, 2);
    m(0, 0) = 0.0; m(0, 1) = 1000.;
    m(1, 0) = -1000.; m(1, 1) = 0.0;

    Matrix expected(2, 2);
    expected(0, 0) = 0.0; expected(0, 1) = 1000.0;
    expected(1, 0) = 0.0; expected(1, 1) = 0.0;

    EXPECT_EQ(m.map(Activations::relu), expected);
}