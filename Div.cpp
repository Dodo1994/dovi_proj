//
// Created by ori on 12/14/18.
//

#include "Div.h"

double Div::calculate() {
    return this->left->calculate() / this->right->calculate();
}
