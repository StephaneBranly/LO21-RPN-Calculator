#ifndef OPERATORARITUNARY_H
#define OPERATORARITUNARY_H

#include "operator.h"
#include <map>
#include <tuple>

namespace Engine {
class ActionUnary;
//Définition de la classe des opérateurs unaires
class OperatorAritUnary :public Operator
{
private:
    std::map<std::string,ActionUnary*> opes;
public:
    OperatorAritUnary(const std::string t): Operator(t,1){}
    void registerActionUnary(std::string type,ActionUnary* a);
    void executeOpe(vector<Expression*> e);
};

class ActionUnary{
public:
    virtual Expression* executeActionUnary(Expression* L) = 0;
};

//Définitions des classes opérateurs unaires
class OperatorNEG : public OperatorAritUnary {
    public:
        OperatorNEG();
        const std::string toString() const override{ return "NEG"; }
        Expression* getCopy() const override { return new OperatorNEG; }
};

//Définitions des actions possibles avec les opérateurs binaires
//opératorNEG
class NegInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

class NegReal : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

class NegRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

}
#endif // OPERATORARITUNARY_H
