#include <utility>
#include <cstring>

//
// Created by ori on 12/20/18.
//

#include "ThreadData.h"

void ThreadData::setIntArg1(int num) {
    this->intArg1=num;
}

void ThreadData::setIntArg2(int num) {
    this->intArg2=num;
}

void ThreadData::setStrArg1(char* str) {
    strcpy(this->strArg1, str);
}

int ThreadData::getIntArg1() {
    return this->intArg1;
}

int ThreadData::getIntArg2() {
    return this->intArg2;
}

char* ThreadData::getStrArg1() {
    return this->strArg1;
}

