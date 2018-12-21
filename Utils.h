#include "Expression.h"
#include <string>
#include <map>
#include <list>
#include "VarData.h"

using namespace std;

class Utils {
public:
    list<string> inFixToPreFix(list<string> inFix);
    list<string> placeValue(list<string> l, map<string, VarData*>* symTbl);
    Expression* preFixToExpression(list<string> preFix);
    Expression* evaluate(list<string> inFix, map<string, VarData *> *symTbl);
};
