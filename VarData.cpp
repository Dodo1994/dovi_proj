//
// Created by ori on 12/16/18.
//

#include "VarData.h"

double VarData::getValue() {
    return this->value;
}

string VarData::getPath() {
    return this->path;
}

void VarData::setValue(double newValue) {
    this->value = newValue;
}

void VarData::setPath(string newPath) {
    this->path = newPath;
}
