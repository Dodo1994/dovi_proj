#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "Interpreter.h"
#include "ReadCode.h"

using namespace std;

// test
int main(int argc, char** argv) {
    ReadCode readCode;
    string input;

    // read from file
    if(argc>1){
        readCode.readFromFile(argv[1]);
        // read from console
    } else {
        readCode.readFromConsole();
    }

    cout<<"this is stupid line"<<endl;

    return 0;
}