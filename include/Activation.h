//
// Created by Kacper Zięba on 30/06/2026.
//

#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <cmath>
#include <algorithm>

namespace Activations {


    inline double sigmoid(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }

    inline double relu(double x) {
        return std::max(0.0, x);
    }

}

#endif //ACTIVATION_H
