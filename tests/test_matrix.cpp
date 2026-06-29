//
// Created by Kacper Zięba on 29/06/2026.
//

#include <gtest/gtest.h>
#include "Matrix.h"

// Test 1: Sprawdzenie inicjalizacji i wymiarów
// Makro TEST przyjmuje dwa argumenty: (NazwaGrupyTestow, NazwaKonkretnegoTestu)
TEST(MatrixTest, Initialization) {
    Matrix m(3, 2);

    // Oczekujemy, że wymiary to 3 i 2
    EXPECT_EQ(m.getNumRows(), 3);
    EXPECT_EQ(m.getNumCols(), 2);

    // Oczekujemy, że nowa macierz jest wypełniona zerami.
    // Używamy EXPECT_DOUBLE_EQ zamiast EXPECT_EQ, ponieważ dla liczb ułamkowych (double)
    // mogą wystąpić minimalne błędy zaokrągleń na poziomie procesora.
    EXPECT_DOUBLE_EQ(m(0, 0), 0.0);
    EXPECT_DOUBLE_EQ(m(2, 1), 0.0);
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
    m(0, 0) = 1.5;
    m(0, 1) = 2.9;
    m(1, 0) = 1.5;
    m(1, 1) = 2.9;
    Matrix m2 = m + m;

    EXPECT_DOUBLE_EQ(m2(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(m2(0, 1), 5.8);
    EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
    EXPECT_DOUBLE_EQ(m2(1, 1), 5.8);
}
TEST(MatrixTest, Subtraction) {
    Matrix m(2, 2);
    m(0, 0) = 1.5;
    m(0, 1) = 2.9;
    m(1, 0) = 1.5;
    m(1, 1) = 2.9;
    Matrix m2 = m - m;

    EXPECT_DOUBLE_EQ(m2(0, 0), 0.0);
    EXPECT_DOUBLE_EQ(m2(0, 1), 0.0);
    EXPECT_DOUBLE_EQ(m2(1, 0), 0.0);
    EXPECT_DOUBLE_EQ(m2(1, 1), 0.0);
}

TEST(MatrixTest, Multiplication) {
    Matrix m1(2, 2);
    m1(0, 0) = 1.0;
    m1(0, 1) = 2.0;
    m1(1, 0) = 3.0;
    m1(1, 1) = 4.0;

    Matrix m2(2,2);
    m2(0, 0) = 4.0;
    m2(0, 1) = 3.0;
    m2(1, 0) = 2.0;
    m2(1, 1) = 1.0;

    Matrix m3 = m1 * m2;

    EXPECT_DOUBLE_EQ(m3(0, 0), 8.0);
    EXPECT_DOUBLE_EQ(m3(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(m3(1, 0), 20.0);
    EXPECT_DOUBLE_EQ(m3(1, 1), 13.0);
}

TEST(MatrixTest, ScalarMultiplication) {
    Matrix m(2, 2);
    m(0, 0) = 1.0;
    m(0, 1) = 2.0;
    m(1, 0) = 1.0;
    m(1, 1) = 2.0;

    Matrix m2 = m * 5;

    EXPECT_DOUBLE_EQ(m2(0, 0), 5.0);
    EXPECT_DOUBLE_EQ(m2(0, 1), 10.0);
    EXPECT_DOUBLE_EQ(m2(1, 0), 5.0);
    EXPECT_DOUBLE_EQ(m2(1, 1), 10.0);
}
