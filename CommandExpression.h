#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression{
    Command* command;

public:
    explicit CommandExpression(Command* command);
    double calculate() override;
};