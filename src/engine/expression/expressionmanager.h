#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include <vector>
#include <list>

#include "expression.h"
#include "expressionabstractfactory.h"
using namespace std;

namespace  Engine{

// Classe du manager d'expression, contient la factory d'expressions
class ExpressionManager{
private:
    ExpressionAbstractFactory* factory;
    std::string contentEval;
public :
    ExpressionManager(){ factory = new ExpressionAbstractFactory; };
    void evalCommandLine (const string str);
    const std::string getContentEval() const { return contentEval; }
    vector<string> split(const string& text, char delimiter);
    Expression* createExpressionFromString (const string s);
    ExpressionAbstractFactory* getFactory(){ return factory; }
};
}

#endif // EXPRESSIONMANAGER_H
