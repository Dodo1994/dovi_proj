#include "Expression.h"

class Number: public Expression {
    double value;

public:
    explicit Number(double value);
    double calculate() override;
};