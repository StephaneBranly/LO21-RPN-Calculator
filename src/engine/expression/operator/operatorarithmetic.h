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

//définitions des actions possibles
//opératorPLUS
class SumIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SumIntReal : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SumIntRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SumRealRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SumRatRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

//OperatorMINUS
class SubIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SubIntReal : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SubIntRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SubRealRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class SubRatRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

//OperatorMUL
class MulIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class MulIntReal : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};


class MulIntRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class MulRealRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class MulRatRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

//OperatorDIV
class DivIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class DivIntReal : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};


class DivIntRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class DivRealRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class DivRatRat : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class OperatorArithmetic :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,Action*> opes;
public:
    OperatorArithmetic(): Operator(2){}
    void registerAction(std::string type1,std::string type2,Action* a);
    void executeOpe(vector<Expression*> e);
};

class OperatorPLUS : public OperatorArithmetic {
        std::string type = "OperatorPLUS";
    public:
        OperatorPLUS();
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "+"; }
        Expression* getCopy() const override { return new OperatorPLUS; }
};

class OperatorMINUS : public OperatorArithmetic {
        std::string type = "OperatorMINUS";
    public:
        OperatorMINUS();
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "-"; }
        Expression* getCopy() const override { return new OperatorMINUS; }
};

class OperatorMUL : public OperatorArithmetic {
        std::string type = "OperatorMUL";
    public:
        OperatorMUL();
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "*"; }
        Expression* getCopy() const override { return new OperatorMUL; }
};

class OperatorDIV : public OperatorArithmetic {
        std::string type = "OperatorDIV";
    public:
        OperatorDIV();
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "/"; }
        Expression* getCopy() const override { return new OperatorDIV; }
};

}

#endif // OPERATORARITHMETIC_H



//<Lreal,Linteger>  | sum(TypeL1*,TypeL2*)



//<int,real>  | sum(TypeL2*,TypeL1*)


//actionSumIntReal
//actionSumIntInt
