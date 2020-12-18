#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"
#include "../litterales/lnumerical.h"

namespace Engine{

class LogicTest;

class OperatorLogic : public Operator
{
    std::map<std::tuple<std::string,std::string>,LogicTest*> tests;
public:
    OperatorLogic(const std::string t, const size_t arrity): Operator(t,arrity){}
    void executeOpe(vector<Expression*> e);
    void registerTest(std::string type1,std::string type2,LogicTest* t);
    ~OperatorLogic();
};

class LogicTest{
public:
    virtual bool test(Expression* E1, Expression* E2) const=0;
    virtual ~LogicTest() = default;
};

class OperatorAnd : public OperatorLogic {
    public:
        OperatorAnd();
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd; }
};

class OperatorOr : public OperatorLogic {
    public:
        OperatorOr();
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr; }
};

class OperatorNot : public OperatorLogic {
    public:
        OperatorNot();
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot; }
};

class OperatorEq : public OperatorLogic {
    public:
        OperatorEq();
        const std::string toString() const override{ return "="; }
        Expression* getCopy() const override { return new OperatorEq; }
};

class OperatorGeq : public OperatorLogic {
    public:
        OperatorGeq();
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq; }
};

class OperatorLeq : public OperatorLogic {
    public:
        OperatorLeq();
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq; }
};
class OperatorGt : public OperatorLogic {
    public:
        OperatorGt();
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt; }
};

class OperatorLt : public OperatorLogic {
    public:
        OperatorLt();
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt; }
};

class OperatorDiff : public OperatorLogic {
    public:
        OperatorDiff();
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff; }
};

class R1testAND : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() && dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testOR : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() || dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() == dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testNOT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E1)->getValue() == 0 ; }
};

class R1testGEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() >= dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testLEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() <= dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testLT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() < dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testGT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() > dynamic_cast<R1value*>(E1)->getValue() ; }
};
class R1testDIFF : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() != dynamic_cast<R1value*>(E1)->getValue() ; }
};
}



#endif // OPERATORLOGIC_H
