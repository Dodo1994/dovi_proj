//
// Created by ori on 12/14/18.
//

#include "Mul.h"

double Mul::calculate() {
    return this->left->calculate() * this->right->calculate();
}
