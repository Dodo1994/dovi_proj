
#ifndef INTERPETER_H
#define INTERPETER_H

using namespace std;

#include <string>
#include <list>

class interpeter {

public:
    list<string> lexer(string input);
    void parser();

private:
    bool is_space(char c);
};


#endif
