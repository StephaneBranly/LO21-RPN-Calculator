#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include <vector>
#include <list>

#include "expression.h"
#include "expressionabstractfactory.h"
using namespace std;

namespace  Engine{
class ExpressionManager{
private:
    list<Expression*> exps;
    ExpressionAbstractFactory* factory;
public :
    ExpressionManager(){ factory = new ExpressionAbstractFactory; };
    void evalCommandLine (const string str);
    vector<string> split(const string& text, char delimiter);
    Expression* createExpressionFromString (const string s);
    ExpressionAbstractFactory* getFactory(){ return factory; }
    ~ExpressionManager();
};
}

#endif // EXPRESSIONMANAGER_H
