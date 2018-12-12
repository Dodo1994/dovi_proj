
#ifndef ORI_LEXER_LEXER_H
#define ORI_LEXER_LEXER_H

using namespace std;

#include <string>
#include <list>

class Lexer {

public:
    list<string> string_to_list(string input);

private:
    bool is_space(char c);
};


#endif //ORI_LEXER_LEXER_H
