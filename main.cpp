#include <iostream>
#include <cstring>
#include <list>
#include <fstream>
#include <sstream>
#include "Interpreter.h"
#include "ReadCode.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        ReadCode readCode;

        // read from file
        if (argc > 1) {
            readCode.readFromFile(argv[1]);
            // read from console
        } else {
            readCode.readFromConsole();
        }

        cout << "that was the most wonderful simulator controller ever forever!!\nbye bye :)\n" << endl;

    } catch (...) {
        cout << "you should be more careful!!" << endl;
    }

    return 0;
}
