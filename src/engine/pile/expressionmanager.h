#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>

namespace  Engine{
class ExpressionManager{ //contient toutes les expressions, et le cycle de vie d'une expression
//Singleton + ITERATOR : choisir le mode d'implémentation
    Expression** exps = nullptr; //pointe sur un tableau d'expression
    size_t nb = 0; //nombre d'adresse stockées
    size_t nbMax = 0; //capacité max du tableau
    void agrandissementCapacite();
    ExpressionManager()=default;
    ~ExpressionManager();

public:
    Expression& addExpression(Operande& op);
    void removeExpression(Expression& e);

    ExpressionManager& getInstance();

};
}
#endif // EXPRESSIONMANAGER_H
