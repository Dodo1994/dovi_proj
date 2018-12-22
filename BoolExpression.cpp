//
// Created by ori on 12/19/18.
//

#include "BoolExpression.h"

double BoolExpression::calculate() {
    if (this->op == ">") {
        return this->left->calculate() > this->right->calculate();
    } else if (this->op == ">=") {
        return this->left->calculate() >= this->right->calculate();
    } else if (this->op == "<") {
        return this->left->calculate() < this->right->calculate();
    } else if (this->op == "<=") {
        return this->left->calculate() <= this->right->calculate();
    } else if (this->op == "==") {
        return this->left->calculate() == this->right->calculate();
    } else if (this->op == "!=") {
        return this->left->calculate() != this->right->calculate();
    }
    return 0;
}
