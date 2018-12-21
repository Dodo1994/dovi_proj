#include "Utils.h"
#include "Number.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include <stack>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

list<string> Utils::inFixToPreFix(list<string> inFix) {
    list<string> preFix;
    stack<string> s;
    queue<string> q;
    string lastOp;

    // can extend to support also OR and AND TODO

    for (auto &it : inFix) {
        // numbers always to the queue
        if (it != "+" && it != "-" && it != "*" && it != "/" && it != "<" && it != ">" && it != "(" && it != ")") {
            q.push(it);
            // ( always to the stack
        } else if (it == "(") {
            s.push(it);
            // * / have priority so to the stack
        } else if (it == "*" || it == "/") {
            s.push(it);
            lastOp = it;
            // no problem with priority so to the stack
        } else if ((it == "+" || it == "-") && (lastOp != "*" && lastOp != "/")) {
            s.push(it);
            lastOp = it;
            // no problem with priority so to the stack
        } else if ((it == "<" || it == ">") && (lastOp != "*" && lastOp != "/" && lastOp != "+" && lastOp != "-")) {
            s.push(it);
            lastOp = it;
            // problem with priority so move high priority to queue
        } else if ((it == "+" || it == "-") && (lastOp == "*" || lastOp == "/")) {
            q.push(s.top());
            s.pop();
            s.push(it);
            lastOp = it;
            // problem with priority so move high priority to queue
        } else if ((it == "<" || it == ">") && (lastOp == "*" || lastOp == "/" || lastOp == "+" || lastOp == "-")) {
            q.push(s.top());
            s.pop();
            s.push(it);
            lastOp = it;
            // to the stack until (
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
        }
    }
    // put all the rest to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // move from queue to list
    while (!q.empty()) {
        preFix.push_front(q.front());
        q.pop();
    }
    return preFix;
}

list<string> Utils::placeValue(list<string> l, map<string, VarData *> *symTbl) {
    list<string> retList;
    for (auto &it : l) {
        if(symTbl->count(it)){
            retList.push_back(to_string(symTbl->at(it)->getValue()));
        } else {
            retList.push_back(it);
        }
    }
    return retList;
}


Expression *Utils::preFixToExpression(list<string> preFix) {
    stack<double> stack;
    preFix.reverse();

    for (auto &it : preFix) {
        if (it != "+" && it != "-" && it != "/" && it != "*" && it != ">" && it != "<") {
            stack.push(stoi(it));
        } else {
            double o1 = stack.top();
            stack.pop();
            double o2 = stack.top();
            stack.pop();

            if (it == "+") {
                stack.push(o1 + o2);
            } else if (it == "-") {
                stack.push(o2 - o1);
            } else if (it == "/") {
                stack.push(o2 / o1);
            } else if (it == "*") {
                stack.push(o1 * o2);
            } else if (it == ">") {
                stack.push(o2 > o1);
            } else if (it == "<") {
                stack.push(o2 < o1);
            } else if (it == ">=") {
                stack.push(o1 * o2);
            } else if (it == "<=") {
                stack.push(o2 > o1);
            } else if (it == "==") {
                stack.push(o2 < o1);
            } else if (it == "!=") {
                stack.push(o2 < o1);
            }
        }
    }
    return new Number(stack.top());
}

Expression *Utils::evaluate(list<string> inFix, map<string, VarData *> *symTbl) {
    return this->preFixToExpression(this->placeValue(this->inFixToPreFix(inFix), symTbl));
}