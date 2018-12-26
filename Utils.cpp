

#include "Utils.h"

bool Utils::isOperator(string str) {
    return (str == "+" || str == "-" || str == "*" || str == "/" || str == ">" || str == "<"
    || str == ">=" || str == "<=" || str == "!=" || str == "==" || str == "OR" || str == "AND");
}

string Utils::removeApostrophes(string str) {
    string newStr;
    // copy all chars to new str without first and last
    for (int i = 1; i < str.size() - 1; ++i) {
        newStr += str[i];
    }
    return newStr;
}

list<string> Utils::infixToPrefix(list<string> infix) {
    // pre process
    infix = this->minusToInt(infix);

    list<string> prefix;
    stack<string> s;
    queue<string> q;
    string lastOp;

    for (auto &it : infix) {
        // numbers always to the queue
        if (!this->isOperator(it) && it != "(" && it != ")") {
            q.push(it);
            // ( always to the stack
        } else if (it == "(") {
            s.push(it);
            lastOp = it;
            // * / have priority so to the stack
        } else if (it == "*" || it == "/") {
            s.push(it);
            lastOp = it;
            // no problem with priority so to the stack
        } else if ((it == "+" || it == "-") && (lastOp != "*" && lastOp != "/")) {
            s.push(it);
            lastOp = it;
            // no problem with priority so to the stack
        } else if ((it == "<" || it == ">" || it == "<=" || it == ">=" || it == "==" || it == "!=")
                   && (lastOp != "*" && lastOp != "/" && lastOp != "+" && lastOp != "-")) {
            s.push(it);
            lastOp = it;
            // no problem with priority so to the stack
        } else if ((it == "OR" || it == "AND") && (lastOp != "*" && lastOp != "/" && lastOp != "+"
                                                   && lastOp != "-" && it != "<" && it != ">" && it != "<=" &&
                                                   it != ">=" && it != "==" && it != "!=")) {
            s.push(it);
            lastOp = it;
            // problem with priority so move high priority to queue
        } else if ((it == "+" || it == "-") && (lastOp == "*" || lastOp == "/")) {
            q.push(s.top());
            s.pop();
            s.push(it);
            lastOp = it;
            // problem with priority so move high priority to queue
        } else if ((it == "<" || it == ">" || it == "<=" || it == ">=" || it == "==" || it == "!=")
                   && (lastOp == "*" || lastOp == "/" || lastOp == "+" || lastOp == "-")) {
            q.push(s.top());
            s.pop();
            s.push(it);
            lastOp = it;
            // problem with priority so move high priority to queue
        } else if ((it == "OR" || it == "AND") && (lastOp == "*" || lastOp == "/" || lastOp == "+" || lastOp == "-"
                                                   || it == "<" || it == ">" || it == "<=" || it == ">=" ||
                                                   it == "==" || it == "!=")) {
            q.push(s.top());
            s.pop();
            s.push(it);
            lastOp = it;
            // to the queue until (
        } else if (it == ")") {
            while (s.top() != "(") {
                q.push(s.top());
                s.pop();
            }
            s.pop();
            if (!s.empty()) {
                lastOp = s.top();
            } else {
                lastOp = "";
            }
        } else {
            throw "be careful!!";
        }
    }
    // put all the rest to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // move from queue to list
    while (!q.empty()) {
        prefix.push_front(q.front());
        q.pop();
    }
    return prefix;
}

list<string> Utils::placeValue(list<string> lst, map<string, VarData *> *symTbl) {
    list<string> retList;
    for (auto &it : lst) {
        // if the str is var, place it's value
        if (symTbl->count(it)) {
            retList.push_back(to_string(symTbl->at(it)->getValue()));
        } else {
            retList.push_back(it);
        }
    }
    return retList;
}

double Utils::prefixToDouble(list<string> prefix) {
    stack<Expression *> stack;
    prefix.reverse();

    for (auto &it : prefix) {
        if (!this->isOperator(it)) {
            stack.push(new Number(stoi(it)));
        } else {
            Expression *o1 = stack.top();
            stack.pop();
            Expression *o2;
            // avoid empty stack case
            if (!stack.empty()) {
                o2 = stack.top();
                stack.pop();
            } else {
                o2 = new Number(0);
            }

            if (it == "+") {
                stack.push(new Plus(o2, o1));
            } else if (it == "-") {
                stack.push(new Minus(o2, o1));
            } else if (it == "/") {
                stack.push(new Div(o2, o1));
            } else if (it == "*") {
                stack.push(new Mul(o2, o1));
            } else if (it == ">") {
                stack.push(new Greater(o2, o1));
            } else if (it == "<") {
                stack.push(new Smaller(o2, o1));
            } else if (it == ">=") {
                stack.push(new GreaterEqual(o2, o1));
            } else if (it == "<=") {
                stack.push(new SmallerEqual(o2, o1));
            } else if (it == "==") {
                stack.push(new Equal(o2, o1));
            } else if (it == "!=") {
                stack.push(new NotEqual(o2, o1));
            } else if (it == "OR") {
                stack.push(new OR(o2, o1));
            } else if (it == "AND") {
                stack.push(new AND(o2, o1));
            } else {
                throw "be careful!!";
            }
        }
    }
    double result = stack.top()->calculate();
    // free all the expressions in the tree
    delete stack.top();
    return result;
}

double Utils::evaluate(list<string> &infix, map<string, VarData *> *symTbl) {
    return this->prefixToDouble(this->infixToPrefix(this->placeValue(infix, symTbl)));
}

list<string> Utils::minusToInt(list<string> lst) {
    auto it = lst.begin();
    // if first is -
    if (*it == "-") {
        if (it != lst.end()) {
            (*it) = "";
            int negNum = -1 * stoi(*(++it));
            (*it) = to_string(negNum);
        }
    }
    // if - after operator or (
    for (it; it != lst.end(); it++) {
        if (*it == "(" || this->isOperator(*it)) {
            if (*(++it) == "-") {
                (*it) = "";
                int negNum = -1 * stoi(*(++it));
                (*it) = to_string(negNum);
            }
        }
    }
    lst.remove("");
    return lst;
}
