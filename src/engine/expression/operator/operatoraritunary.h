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
    ~OperatorAritUnary();
};

class ActionUnary{
public:
    virtual Expression* executeActionUnary(Expression* L) = 0;
    virtual ~ActionUnary() = default;
};

//Définitions des classes opérateurs unaires
class OperatorNEG : public OperatorAritUnary {
    public:
        OperatorNEG();
        const std::string toString() const override{ return "NEG"; }
        Expression* getCopy() const override { return new OperatorNEG; }
};

class OperatorNUM : public OperatorAritUnary {
    public:
        OperatorNUM();
        const std::string toString() const override{ return "NUM"; }
        Expression* getCopy() const override { return new OperatorNUM; }
};

class OperatorDEN : public OperatorAritUnary {
    public:
        OperatorDEN();
        const std::string toString() const override{ return "DEN"; }
        Expression* getCopy() const override { return new OperatorDEN; }
};

class OperatorSIN : public OperatorAritUnary {
    public:
        OperatorSIN();
        const std::string toString() const override{ return "SIN"; }
        Expression* getCopy() const override { return new OperatorSIN; }
};

class OperatorCOS : public OperatorAritUnary {
    public:
        OperatorCOS();
        const std::string toString() const override{ return "COS"; }
        Expression* getCopy() const override { return new OperatorCOS; }
};

class OperatorTAN : public OperatorAritUnary {
    public:
        OperatorTAN();
        const std::string toString() const override{ return "TAN"; }
        Expression* getCopy() const override { return new OperatorTAN; }
};

class OperatorARCSIN : public OperatorAritUnary {
    public:
        OperatorARCSIN();
        const std::string toString() const override{ return "ARCSIN"; }
        Expression* getCopy() const override { return new OperatorARCSIN; }
};

class OperatorARCCOS : public OperatorAritUnary {
    public:
        OperatorARCCOS();
        const std::string toString() const override{ return "ARCCOS"; }
        Expression* getCopy() const override { return new OperatorARCCOS; }
};

class OperatorARCTAN : public OperatorAritUnary {
    public:
        OperatorARCTAN();
        const std::string toString() const override{ return "ARCTAN"; }
        Expression* getCopy() const override { return new OperatorARCTAN; }
};


class OperatorSQRT : public OperatorAritUnary {
    public:
        OperatorSQRT();
        const std::string toString() const override{ return "SQRT"; }
        Expression* getCopy() const override { return new OperatorSQRT; }
};


class OperatorEXP : public OperatorAritUnary {
    public:
        OperatorEXP();
        const std::string toString() const override{ return "EXP"; }
        Expression* getCopy() const override { return new OperatorEXP; }
};


class OperatorLN : public OperatorAritUnary {
    public:
        OperatorLN();
        const std::string toString() const override{ return "LN"; }
        Expression* getCopy() const override { return new OperatorLN; }
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

//opéraotrNUM
class NumInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

class NumRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorDEN
class DenInt : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

class DenRat : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorSIN
class SinR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorCOS
class CosR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorTAN
class TanR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorARCSIN
class ArcsinR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorARCCOS
class ArccosR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorARCTAN
class ArctanR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorSQRT
class SqrtR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorEXP
class ExpR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};

//OpératorLN
class LnR1 : public ActionUnary {
    Expression * executeActionUnary(Expression *L) override;
};
}
#endif // OPERATORARITUNARY_H
