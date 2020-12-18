#ifndef OperatorAritBinary_H
#define OperatorAritBinary_H

#include "operator.h"
#include <map>
#include <tuple>

namespace Engine {
class ActionBinary;
//Définition de la classe des opérateurs binaires
class OperatorAritBinary :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,ActionBinary*> opes;
public:
    OperatorAritBinary(const std::string t): Operator(t,2){}
    OperatorAritBinary(const OperatorAritBinary & o);
    void registerActionBinary(std::string type1,std::string type2,ActionBinary* a);
    void executeOpe(vector<Expression*> e);
    ~OperatorAritBinary();
};

class ActionBinary{
public:
    virtual Expression* executeActionBinary(Expression* L1, Expression* L2) = 0;
    virtual ~ActionBinary() = default;
    virtual ActionBinary* getCopy() const = 0;
};


//Définitions classes opérateurs binaires
class OperatorPLUS : public OperatorAritBinary {
    public:
        OperatorPLUS();
        const std::string toString() const override{ return "+"; }
        Expression* getCopy() const override { return new OperatorPLUS(*this); }
};

class OperatorMINUS : public OperatorAritBinary {
    public:
        OperatorMINUS();
        const std::string toString() const override{ return "-"; }
        Expression* getCopy() const override { return new OperatorMINUS(*this); }
};

class OperatorMUL : public OperatorAritBinary {
    public:
        OperatorMUL();
        const std::string toString() const override{ return "*"; }
        Expression* getCopy() const override { return new OperatorMUL(*this); }
};

class OperatorDIV : public OperatorAritBinary {
    public:
        OperatorDIV();
        const std::string toString() const override{ return "/"; }
        Expression* getCopy() const override { return new OperatorDIV(*this); }
};

class OperatorDIVINT : public OperatorAritBinary {
    public:
        OperatorDIVINT();
        const std::string toString() const override{ return "DIV"; }
        Expression* getCopy() const override { return new OperatorDIVINT(*this); }
};

class OperatorMOD : public OperatorAritBinary {
    public:
        OperatorMOD();
        const std::string toString() const override{ return "MOD"; }
        Expression* getCopy() const override { return new OperatorMOD(*this); }
};

class OperatorPOW : public OperatorAritBinary {
    public:
        OperatorPOW();
        const std::string toString() const override{ return "POW"; }
        Expression* getCopy() const override { return new OperatorPOW(*this); }
};

//Définitions des ActionBinarys possibles avec les opérateurs binaires
//opératorPLUS
class SumIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

class SumIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

class SumIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

class SumRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

class SumRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

//OperatorMINUS
class SubIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SumIntInt; }
};

class SubIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SubIntReal; }
};

class SubIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SubIntRat; }
};

class SubRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SubRealRat; }
};

class SubRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new SubRatRat; }
};

//OperatorMUL
class MulIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new MulIntInt; }
};

class MulIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new MulIntReal; }
};


class MulIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new MulIntRat; }
};

class MulRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new MulRealRat; }
};

class MulRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new MulRatRat; }
};

//OperatorDIV
class DivIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivIntInt; }
};

class DivIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivIntReal; }
};

class DivIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivIntRat; }
};

class DivRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivRealRat; }
};

class DivRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivRatRat; }
};

//OperatorDIVINT pour la division entière
class DivintIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new DivintIntInt; }
};

//Operator MOD
class ModIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new ModIntInt; }
};

//Operator POW
class PowIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new PowIntInt; }
};

class PowRealInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new PowRealInt; }
};

class PowRatInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2) override;
    ActionBinary* getCopy() const override { return new PowRatInt; }
};

}


#endif // OperatorAritBinary_H
