//
// Created by Kacper Zięba on 29/06/2026.
//

#include "Layer.h"

#include <random>

Layer::Layer(size_t inputSize, size_t outputSize, std::function<double(double)> activationFunc)
    : weights(outputSize, inputSize), bias(outputSize, 1), activation(activationFunc) {

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);

    const auto& data = weights.getData();

    for (int i = 0; i < weights.getNumRows(); i++) {
        for (int j = 0; j < weights.getNumCols(); j++) {
            weights(i, j) = distribution(generator)*std::sqrt(2.0/inputSize);
        }
    }
}

Matrix Layer::forward(const Matrix &input) {
    Matrix z = (weights*input) + bias;
    return z.map(this->activation);
}

