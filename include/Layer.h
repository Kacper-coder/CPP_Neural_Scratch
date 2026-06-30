//
// Created by Kacper Zięba on 29/06/2026.
//

#ifndef LAYER_H
#define LAYER_H
#include "Matrix.h"

class Layer {
    private:
    Matrix weights;
    Matrix bias;
    std::function<double(double)> activation;

    public:
    Layer(size_t inputSize, size_t outputSize, std::function<double(double)> activationFunc);

    Matrix forward(const Matrix& input);
};

#endif //LAYER_H
