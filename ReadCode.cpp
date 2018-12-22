

#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "ReadCode.h"
#include "Interpreter.h"

void ReadCode::readFromFile(string fileName) {
    Interpreter interpreter;
    ifstream infile;
    infile.open (fileName);
    string input(dynamic_cast<stringstream const&>(stringstream() << infile.rdbuf()).str());
    infile.close();
    vector<string> v = interpreter.lexer(input);

    // lexer test
    //TODO this->displayLexerResult(v);

    // parser
    interpreter.parser(v);
}

void ReadCode::readFromConsole() {
    Interpreter interpreter;
    cout<<"type your code (to finish type 'quit')"<<endl;

    string line;
    while (true){
        line="";
        getline(cin,line);
        if(line=="quit"){ break;}
        interpreter.parser(interpreter.lexer(line));
    }
}

void ReadCode::displayLexerResult(vector<string> v) {
    // test lexer result
    for (auto &it : v)
        cout << it << "\n";
}
