#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "Interpreter.h"

using namespace std;

// test
int main() {
    Interpreter interpreter;

    ifstream infile;
    infile.open ("flight_code.txt");
    // one of the scariest lines i ever seen
    string input(dynamic_cast<stringstream const&>(stringstream() << infile.rdbuf()).str());
    vector<string> l = interpreter.lexer(input);

    // display lexer result
    for (auto &it : l)
        cout << it << " ";


    interpreter.parser(l);
    // display vars
    interpreter.displayVars();

    //

    cout<<"this is stupid line"<<endl;

    infile.close();

    return 0;
}
