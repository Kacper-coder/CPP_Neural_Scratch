//
// Created by Kacper Zięba on 29/06/2026.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix {
    private:
    int rows;
    int cols;

    //1D vector will should be faster than creating and reading from 2D vector
    std::vector<double> data;

    public:
    //Constructor
    Matrix(int r, int c );

    //Getters
    int getNumRows() const;
    int getNumCols() const;

    //Helper method
    void print() const;

    //neccesary operator overloads
    double& operator()(int r, int c);
    const double& operator()(int r, int c) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;

};

#endif //MATRIX_H
