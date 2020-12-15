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

//OperatorDIVINT pour la division entière
class DivintIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

//Operator MOD
class ModIntInt : public Action {
    Expression* executeAction(Expression* L1,Expression* L2);
};

class OperatorArithmetic :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,Action*> opes;
public:
    OperatorArithmetic(const std::string t): Operator(t,2){}
    void registerAction(std::string type1,std::string type2,Action* a);
    void executeOpe(vector<Expression*> e);
};

class OperatorPLUS : public OperatorArithmetic {
    public:
        OperatorPLUS();
        const std::string toString() const override{ return "+"; }
        Expression* getCopy() const override { return new OperatorPLUS; }
};

class OperatorMINUS : public OperatorArithmetic {
    public:
        OperatorMINUS();
        const std::string toString() const override{ return "-"; }
        Expression* getCopy() const override { return new OperatorMINUS; }
};

class OperatorMUL : public OperatorArithmetic {
    public:
        OperatorMUL();
        const std::string toString() const override{ return "*"; }
        Expression* getCopy() const override { return new OperatorMUL; }
};

class OperatorDIV : public OperatorArithmetic {
    public:
        OperatorDIV();
        const std::string toString() const override{ return "/"; }
        Expression* getCopy() const override { return new OperatorDIV; }
};

class OperatorDIVINT : public OperatorArithmetic {
    public:
        OperatorDIVINT();
        const std::string toString() const override{ return "DIV"; }
        Expression* getCopy() const override { return new OperatorDIVINT; }
};

class OperatorMOD : public OperatorArithmetic {
    public:
        OperatorMOD();
        const std::string toString() const override{ return "MOD"; }
        Expression* getCopy() const override { return new OperatorMOD; }
};

class OperatorNEG : public Operator {
public:
    OperatorNEG(): Operator("OperatorNEG",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "NEG"; }
    Expression* getCopy() const override { return new OperatorNEG; }
};

}

#endif // OPERATORARITHMETIC_H



