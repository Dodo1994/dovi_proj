//
// Created by ori on 12/14/18.
//

#include "Plus.h"

double Plus::calculate() {
    return this->left->calculate() + this->right->calculate();
}
