
#include "Expression.h"
#include <list>

using namespace std;

class ExpsCollection {
    list<Expression*> expressions;

public:
    ExpsCollection();
    ~ExpsCollection();
    void addExpression(Expression* expression);
    void executeAll();
    void deleteAll();
};
