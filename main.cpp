#include <iostream>
#include <cstring>
#include <list>
#include "Lexer.h"

using namespace std;

// test for lexer
int main() {
    Lexer lexer;

    list<string> l = lexer.string_to_list("I am Ori. This is so cool\toop\noop");

    for (auto &it : l)
        std::cout << it << endl;

    cout<<"this is stupid line"<<endl;
    return 0;
}