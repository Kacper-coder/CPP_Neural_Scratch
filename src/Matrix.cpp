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

double& Matrix::operator()(int r, int c) {
     return data[r * cols + c];
 }

const double& Matrix::operator()(int r, int c) const {
     return data[r * cols + c];
 }

Matrix Matrix::operator+(const Matrix& other) const {
     if (this->cols != other.rows) {
         throw std::invalid_argument("Blad! Liczba kolumn 1. macierzy musi byc rowna liczbie wierszy 2. macierzy.");
     }

     Matrix result(*this);
     for (int i = 0; i < getNumRows(); i++) {
         for (int j = 0; j < getNumCols(); j++) {
             result(i, j) += other(i, j);
         }
     }
    return result;
 }

Matrix Matrix::operator-(const Matrix& other) const {
     if (this->cols != other.rows) {
         throw std::invalid_argument("Blad! Liczba kolumn 1. macierzy musi byc rowna liczbie wierszy 2. macierzy.");
     }

     Matrix result(*this);
     for (int i = 0; i < getNumRows(); i++) {
         for (int j = 0; j < getNumCols(); j++) {
             result(i, j) -= other(i, j);
         }
     }
    return result;
 }

Matrix Matrix::operator*(const Matrix &other) const {
     if (this->cols != other.rows) {
         throw std::invalid_argument("Blad! Liczba kolumn 1. macierzy musi byc rowna liczbie wierszy 2. macierzy.");
     }
     Matrix result(this->rows, other.getNumRows());

    for (int i = 0; i < this->getNumRows(); i++) {
        for (int j = 0; j < other.getNumCols(); j++) {
            double sum = 0.0;
            for (int k = 0; k < this->getNumCols(); k++) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
     return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(this->getNumRows(), this->getNumCols());

     for (int i = 0; i < this->getNumRows() * this->getNumCols(); i++) {
         result.data[i] = this->data[i] * scalar;
     }
     return result;
}

void Matrix::print() const {
    for (int i = 0; i < this->getNumRows(); i++) {
        for (int j = 0; j < this->getNumCols(); j++) {
            std::cout << this->data[i * this->getNumCols() + j] << " ";
        }
        std::cout << "\n";
    }
}




