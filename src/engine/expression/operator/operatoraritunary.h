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
    OperatorAritUnary(const OperatorAritUnary & o);
    void registerActionUnary(std::string type,ActionUnary* a);
    void executeOpe(vector<Expression*> e);
    ~OperatorAritUnary();
};

class ActionUnary{
public:
    virtual Expression* executeActionUnary(Expression* L) = 0;
    virtual ~ActionUnary() = default;
    virtual ActionUnary* getCopy() const = 0;
};

//Définitions des classes opérateurs unaires
class OperatorNEG : public OperatorAritUnary {
    public:
        OperatorNEG();
        const std::string toString() const override{ return "NEG"; }
        Expression* getCopy() const override { return new OperatorNEG(*this); }
};

class OperatorNUM : public OperatorAritUnary {
    public:
        OperatorNUM();
        const std::string toString() const override{ return "NUM"; }
        Expression* getCopy() const override { return new OperatorNUM(*this); }
};

class OperatorDEN : public OperatorAritUnary {
    public:
        OperatorDEN();
        const std::string toString() const override{ return "DEN"; }
        Expression* getCopy() const override { return new OperatorDEN(*this); }
};

class OperatorSIN : public OperatorAritUnary {
    public:
        OperatorSIN();
        const std::string toString() const override{ return "SIN"; }
        Expression* getCopy() const override { return new OperatorSIN(*this); }
};

class OperatorCOS : public OperatorAritUnary {
    public:
        OperatorCOS();
        const std::string toString() const override{ return "COS"; }
        Expression* getCopy() const override { return new OperatorCOS(*this); }
};

class OperatorTAN : public OperatorAritUnary {
    public:
        OperatorTAN();
        const std::string toString() const override{ return "TAN"; }
        Expression* getCopy() const override { return new OperatorTAN(*this); }
};

class OperatorARCSIN : public OperatorAritUnary {
    public:
        OperatorARCSIN();
        const std::string toString() const override{ return "ARCSIN"; }
        Expression* getCopy() const override { return new OperatorARCSIN(*this); }
};

class OperatorARCCOS : public OperatorAritUnary {
    public:
        OperatorARCCOS();
        const std::string toString() const override{ return "ARCCOS"; }
        Expression* getCopy() const override { return new OperatorARCCOS(*this); }
};

class OperatorARCTAN : public OperatorAritUnary {
    public:
        OperatorARCTAN();
        const std::string toString() const override{ return "ARCTAN"; }
        Expression* getCopy() const override { return new OperatorARCTAN(*this); }
};


class OperatorSQRT : public OperatorAritUnary {
    public:
        OperatorSQRT();
        const std::string toString() const override{ return "SQRT"; }
        Expression* getCopy() const override { return new OperatorSQRT(*this); }
};


class OperatorEXP : public OperatorAritUnary {
    public:
        OperatorEXP();
        const std::string toString() const override{ return "EXP"; }
        Expression* getCopy() const override { return new OperatorEXP(*this); }
};


class OperatorLN : public OperatorAritUnary {
    public:
        OperatorLN();
        const std::string toString() const override{ return "LN"; }
        Expression* getCopy() const override { return new OperatorLN(*this); }
};

//Définitions des actions possibles avec les opérateurs binaires
//opératorNEG
class NegInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new NegInt; }
};

class NegReal : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new NegReal; }
};

class NegRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new NegRat; }
};

//opéraotrNUM
class NumInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new NumInt; }
};

class NumRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new NumRat; }
};

//OpératorDEN
class DenInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new DenInt; }
};

class DenRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new DenRat; }
};

//OpératorSIN
class SinR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new SinR1; }
};

//OpératorCOS
class CosR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new CosR1; }
};

//OpératorTAN
class TanR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new TanR1; }
};

//OpératorARCSIN
class ArcsinR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new ArcsinR1; }
};

//OpératorARCCOS
class ArccosR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new ArccosR1; }
};

//OpératorARCTAN
class ArctanR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new ArctanR1; }
};

//OpératorSQRT
class SqrtR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new SqrtR1; }
};

//OpératorEXP
class ExpR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new ExpR1; }
};

//OpératorLN
class LnR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
    ActionUnary* getCopy() const override { return new LnR1; }
};
}
#endif // OPERATORARITUNARY_H
