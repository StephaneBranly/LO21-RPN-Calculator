#ifndef OPERATORARITHMETIC_H
#define OPERATORARITHMETIC_H

#include "operator.h"
#include <map>
#include <tuple>

namespace Engine {


class Action{
public:
    virtual Expression* executeAction(Expression* L1, Expression* L2) = 0;
};

class SumIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
}; //pour chaque

class OperatorArithmetic :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,Action*> opes;
public:
    void registerAction(std::string type1,std::string type2,Action* a);
    virtual size_t getArrity () const =0;
    void executeOpe();
};

class OperatorPLUS : public OperatorArithmetic {
        size_t arrity=2;
        std::string type = "OperatorPLUS";
    public:
        OperatorPLUS();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "+"; }
        Expression* getCopy() const override { return new OperatorPLUS; }
};

}

#endif // OPERATORARITHMETIC_H



//<Lreal,Linteger>  | sum(TypeL1*,TypeL2*)



//<int,real>  | sum(TypeL2*,TypeL1*)


//actionSumIntReal
//actionSumIntInt
