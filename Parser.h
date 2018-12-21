using namespace std;

#include <string>
#include <vector>
#include "CommandFactory.h"
#include "ExpsCollection.h"

class Parser {
public:
    void parse(vector<string> &code, ExpsCollection* expressions,
               CommandFactory* factory, map<string,string>* codeMap);
};