//
// Created by ori on 12/17/18.
//

#include <iostream>
#include "ExpsCollection.h"

ExpsCollection::~ExpsCollection() {
    this->deleteAll();
}

void ExpsCollection::addExpression(Expression *expression) {
    this->expressions.push_back(expression);
}

void ExpsCollection::executeAll() {
    for (auto &it : this->expressions) {
        it->calculate();
    }
}

ExpsCollection::ExpsCollection() {
}

void ExpsCollection::deleteAll() {
    for (auto &it : this->expressions)
        delete it;
    this->expressions.clear();
}
