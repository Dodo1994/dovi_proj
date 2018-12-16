
#ifndef ORI_LEXER_VARDATA_H
#define ORI_LEXER_VARDATA_H

#include <string>

using namespace std;

class VarData {
double value;
string path;

public:
    VarData(double value, string path);
    double getValue();
    string getPath();
    void setValue(double newValue);
    void setPath(string newPath);

};


#endif //ORI_LEXER_VARDATA_H
