#ifndef OPERATORARITHMETIC_H
#define OPERATORARITHMETIC_H

#include "operator.h"
#include <map>
#include <tuple>

namespace Engine {


class Action{
    Expression* L1;
    Expression* L2;
public:
    Action(Expression* a,Expression* b):L1(a),L2(b){}
    virtual Expression* executeAction() = 0;
};

class OperatorArithmetic :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,Action*> opes;
public:
    void registerAction(std::string type1,std::string type2,Action* a);
    size_t getArrity () const override { return arrity; }
    OperatorArithmetic();
    virtual void executeOpe() = 0;
};

}
#endif // OPERATORARITHMETIC_H



<Lreal,Linteger>  | sum(TypeL1*,TypeL2*)



<int,real>  | sum(TypeL2*,TypeL1*)


actionSumIntReal
actionSumIntInt
