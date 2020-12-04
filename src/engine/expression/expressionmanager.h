#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include <vector>
#include <list>

#include "expression.h"

using namespace std;

namespace  Engine{
/*
class ExpressionManager{
    Expression** exps = nullptr; //pointe sur un tableau d'expression
    //vector<Expression*> exps;
    vector<Expression*> expressionsTypes;
    size_t nb = 0; //nombre d'adresse stockées
    size_t nbMax = 0; //capacité max du tableau
    void agrandissementCapacite();
    ExpressionManager()=default;
public:
    void registerType(const Expression* type);
    Expression& addExpression(Expression& e);//ajoute une expression au tableau
    void removeExpression(Expression& e);//supprime une expression du tableau
    //ExpressionManager& getInstance(); singleton.
    void evalCommandLine (const string str);//evalue la command line => ce qui est entré par l'utilisateur
    vector<string> split(const string& text, char delimiter);
    Expression* CreateExpressionFromString (const string s);//création d'une expression à partir d'un string
};
}
*/

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
