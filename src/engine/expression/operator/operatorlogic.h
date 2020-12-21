#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"
#include "../litterales/lnumerical.h"

namespace Engine{

class LogicTest;

// Definition des operateurs logiques et de comparaisons
class OperatorLogic : public Operator
{
protected:
    std::map<std::tuple<std::string,std::string>,LogicTest*> tests;
public:
    OperatorLogic(const std::string t, const size_t arrity): Operator(t,arrity){}
    OperatorLogic(const OperatorLogic & o);
    void executeOpe(vector<Expression*> e);
    void registerTest(std::string type1,std::string type2,LogicTest* t);
    ~OperatorLogic();
};

class LogicTest{
public:
    virtual bool test(Expression* E1, Expression* E2) const=0;
    virtual ~LogicTest() = default;
    virtual LogicTest* getCopy() const = 0;
};

class OperatorAnd : public OperatorLogic {
    public:
        OperatorAnd();
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd(*this); }
};

class OperatorOr : public OperatorLogic {
    public:
        OperatorOr();
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr(*this); }
};

class OperatorNot : public OperatorLogic {
    public:
        friend class OperatorLogic;
        OperatorNot();
        OperatorNot(const OperatorNot & o);
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot(*this); }
};

class OperatorEq : public OperatorLogic {
    public:
        OperatorEq();
        const std::string toString() const override{ return "="; }
        Expression* getCopy() const override { return new OperatorEq(*this); }
};

class OperatorGeq : public OperatorLogic {
    public:
        OperatorGeq();
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq(*this); }
};

class OperatorLeq : public OperatorLogic {
    public:
        OperatorLeq();
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq(*this); }
};
class OperatorGt : public OperatorLogic {
    public:
        OperatorGt();
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt(*this); }
};

class OperatorLt : public OperatorLogic {
    public:
        OperatorLt();
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt(*this); }
};

class OperatorDiff : public OperatorLogic {
    public:
        OperatorDiff();
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff(*this); }
};

class R1testAND : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() && dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testAND; }
};
class R1testOR : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() || dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testOR; }
};
class R1testEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() == dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testEQ; }
};
class R1testNOT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E1)->getValue() == 0 ; }
    LogicTest* getCopy() const override { return new R1testNOT; }
};

class R1testGEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() >= dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testGEQ; }
};
class R1testLEQ : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() <= dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testLEQ; }
};
class R1testLT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() < dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testLT; }
};
class R1testGT : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() > dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testGT; }
};
class R1testDIFF : public LogicTest
{
    bool test(Expression* E1, Expression* E2) const override { return dynamic_cast<R1value*>(E2)->getValue() != dynamic_cast<R1value*>(E1)->getValue() ; }
    LogicTest* getCopy() const override { return new R1testDIFF; }
};
}



#endif // OPERATORLOGIC_H
