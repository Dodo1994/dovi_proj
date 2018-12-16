#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "Interpreter.h"

using namespace std;

void lexerTest(vector<string> v) {
    // test lexer result
    for (auto &it : v)
        cout << it << "\n";
}

// test
int main() {
    Interpreter interpreter;

    // read from file the code to test our stuff
    ifstream infile;
    infile.open ("flight_code.txt");
    // one of the scariest lines i ever seen
    string input(dynamic_cast<stringstream const&>(stringstream() << infile.rdbuf()).str());
    vector<string> v = interpreter.lexer(input);

    // lexer test
    lexerTest(v);

    //interpreter.displaySymTbl();

    // parser
    interpreter.parser(v);

    cout<<"this is stupid line"<<endl;

    infile.close();

    return 0;
}
