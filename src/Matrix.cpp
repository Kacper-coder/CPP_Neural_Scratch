//
// Created by Kacper Zięba on 29/06/2026.
//

#include "Matrix.h"

#include <iostream>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
     data.resize(r * c, 0.0);
 }

int Matrix::getNumCols() const {
    return cols;
}

int Matrix::getNumRows() const {
     return rows;
 }

const std::vector<double>& Matrix::getData() const {
    return this->data;
}

double& Matrix::operator()(int r, int c) {
     return data[r * cols + c];
 }

const double& Matrix::operator()(int r, int c) const {
     return data[r * cols + c];
 }

Matrix& Matrix::operator+=(const Matrix& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Blad! Macierze musza miec identyczne wymiary do +=.");
    }

    for (int i = 0; i < this->rows*this->cols; i++) {
        this->data[i] += other.data[i];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Blad! Macierze musza miec identyczne wymiary do -=.");
    }

    for (int i = 0; i < this->rows*this->cols; i++) {
        this->data[i] -= other.data[i];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Blad! Macierze musza miec identyczne wymiary do +.");
    }

     Matrix result(*this);
     result += other;
    return result;
 }

Matrix Matrix::operator-(const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Blad! Macierze musza miec identyczne wymiary do -.");
    }

     Matrix result(*this);
     result -= other;
    return result;
 }

Matrix Matrix::operator*(const Matrix &other) const {
     if (this->cols != other.rows) {
         throw std::invalid_argument("Blad! Liczba kolumn 1. macierzy musi byc rowna liczbie wierszy 2. macierzy.");
     }
     Matrix result(this->rows, other.getNumCols());

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.getNumCols(); j++) {
            double sum = 0.0;
            for (int k = 0; k < this->cols; k++) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
     return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(this->rows, this->cols);

     for (int i = 0; i < this->rows * this->cols; i++) {
         result.data[i] = this->data[i] * scalar;
     }
     return result;
}


Matrix Matrix::transpose() const {

    Matrix result(this->cols, this->rows);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result(j,i) = (*this)(i, j);
        }
    }
    return result;
}

Matrix Matrix::hadamard(const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Blad! Macierze musza miec identyczne wymiary do hadamard.");
    }
    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows * this->cols; i++) {
        result.data[i] = this->data[i] * other.data[i];
    }

    return result;
}

Matrix Matrix::map(const std::function<double(double)>& func) const {

    Matrix result(this->rows, this->cols);

    for (int i = 0; i < this->rows * this->cols; i++) {
        result.data[i] = func(this->data[i]);
    }
    return result;
}

bool Matrix::operator==(const Matrix &other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        return false;
    }

    for (int i = 0; i < this->rows*this->cols; i++) {
        if (std::abs(this->data[i] - other.data[i]) > 1e-9) {
            return false;
        }
    }
    return true;
}


void Matrix::print() const {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cout << this->data[i * this->cols + j] << " ";
        }
        std::cout << "\n";
    }
}




