#include "BinaryExpression.h"

void BinaryExpression::setRight(Expression *right) {
    this->right=right;
}

void BinaryExpression::setLeft(Expression *left) {
    this->left=left;
}

double BinaryExpression::calculate() {
    return 0;
}