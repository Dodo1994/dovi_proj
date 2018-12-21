#include <cmath>
#include <string>
#include "BinaryExpression.h"

using namespace std;

class BoolExpression : public BinaryExpression{
    string op;

public:
    double calculate();
};


