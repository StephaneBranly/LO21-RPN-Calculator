#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include "expression.h"
#include <vector>
using namespace std;

namespace  Engine{
class ExpressionManager{
    Expression** exps = nullptr; //pointe sur un tableau d'expression
    size_t nb = 0; //nombre d'adresse stockées
    size_t nbMax = 0; //capacité max du tableau
    void agrandissementCapacite();
    ExpressionManager()=default;
    ~ExpressionManager();

public:
    Expression& addExpression(Expression& e);//ajoute une expression au tableau
    void removeExpression(Expression& e);//supprime une expression du tableau
    //ExpressionManager& getInstance(); singleton.

    type_literal gettype(const string& str)const; //détermine le type d'une expression

    void evalCommandLine (const string str);//evalue la command line => ce qui est entré par l'utilisateur
    vector<string> split(const string& text, char delimiter);
    Expression& CreateExpressionFromString (const string s);//création d'une expression à partir d'un string
};
}
#endif // EXPRESSIONMANAGER_H
