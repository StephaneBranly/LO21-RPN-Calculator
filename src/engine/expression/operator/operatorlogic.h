#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"
#include "../litterales/lnumerical.h"

namespace Engine{

class OperatorLogic :public Operator
{
public:
    OperatorLogic(const std::string t, const size_t arrity): Operator(t,arrity){}
    void executeOpe(vector<Expression*> e);
    virtual bool test(Lnumerical* E1, Lnumerical* E2) const=0;
};


class OperatorAnd : public OperatorLogic {
    public:
        OperatorAnd(): OperatorLogic("OperatorAND",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd; }
};

class OperatorOr : public OperatorLogic {
    public:
        OperatorOr(): OperatorLogic("OperatorOR",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr; }
};

class OperatorNot : public OperatorLogic {
    public:
        OperatorNot(): OperatorLogic("OperatorNOT",1){}
        bool test(Lnumerical* E1, Lnumerical* E2=nullptr) const override ;
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot; }
};

class OperatorEq : public OperatorLogic {
    public:
        OperatorEq(): OperatorLogic("OperatorEq",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "="; }
        Expression* getCopy() const override { return new OperatorEq; }
};

class OperatorGeq : public OperatorLogic {
    public:
        OperatorGeq(): OperatorLogic("OperatorGeq",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq; }
};

class OperatorLeq : public OperatorLogic {
    public:
        OperatorLeq(): OperatorLogic("OperatorLeq",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq; }
};
class OperatorGt : public OperatorLogic {
    public:
        OperatorGt(): OperatorLogic("OperatorGt",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt; }
};

class OperatorLt : public OperatorLogic {
    public:
        OperatorLt(): OperatorLogic("OperatorLt",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt; }
};

class OperatorDiff : public OperatorLogic {
    public:
        OperatorDiff(): OperatorLogic("OperatorDiff",2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff; }
};


}



#endif // OPERATORLOGIC_H
