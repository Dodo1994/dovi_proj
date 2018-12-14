
#ifndef ORI_LEXER_COMMAND_H
#define ORI_LEXER_COMMAND_H

#include <vector>
#include <string>

class Command {
protected:
    std::vector<std::string> args;

public:
    Command(std::vector<std::string> args);
    virtual void execute();
};


#endif //ORI_LEXER_COMMAND_H
