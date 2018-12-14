
#ifndef ORI_LEXER_COMMAND_H
#define ORI_LEXER_COMMAND_H

#include <vector>
#include <string>
#include "Interpreter.h"

class Command {
protected:
    vector<string> args;
    Interpreter* interpreter;

public:
    Command(vector<string> args, Interpreter* interpreter);
    virtual void execute()=0;
};


#endif //ORI_LEXER_COMMAND_H
