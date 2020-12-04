#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include <vector>
#include <list>

#include "expression.h"

using namespace std;

namespace  Engine{
class ExpressionManager{
private:
    list<Expression*> exps;
    vector<Expression> expressionsTypes;
public :
    ExpressionManager() = default;
    ExpressionManager& operator<<(Expression& e);
    void registerType(const Expression& type);
    void evalCommandLine (const string str);
    vector<string> split(const string& text, char delimiter);
    Expression* CreateExpressionFromString (const string s);
    virtual ~ExpressionManager();
};
}

#endif // EXPRESSIONMANAGER_H
