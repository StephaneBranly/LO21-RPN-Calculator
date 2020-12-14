#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"
#include "../litterales/lnumerical.h"

namespace Engine{

class OperatorLogic :public Operator
{
public:
    OperatorLogic(const size_t arrity): Operator(arrity){}
    void executeOpe(vector<Expression*> e);
    virtual bool test(Lnumerical* E1, Lnumerical* E2) const=0;
};


class OperatorAnd : public OperatorLogic {
        std::string type = "AND";
    public:
        OperatorAnd(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd; }
};

class OperatorOr : public OperatorLogic {
        std::string type = "OperatorOr";
    public:
        OperatorOr(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr; }
};

class OperatorNot : public OperatorLogic {
        std::string type = "OperatorNot";
    public:
        OperatorNot(): OperatorLogic(1){}
        bool test(Lnumerical* E1, Lnumerical* E2=nullptr) const override ;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot; }
};

class OperatorEq : public OperatorLogic {
        std::string type = "OperatorEq";
    public:
        OperatorEq(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "="; }
        Expression* getCopy() const override { return new OperatorEq; }
};

class OperatorGeq : public OperatorLogic {
        std::string type = "OperatorGeq";
    public:
        OperatorGeq(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq; }
};

class OperatorLeq : public OperatorLogic {
        std::string type = "OperatorLeq";
    public:
        OperatorLeq(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq; }
};
class OperatorGt : public OperatorLogic {
        std::string type = "OperatorGt";
    public:
        OperatorGt(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt; }
};

class OperatorLt : public OperatorLogic {
        std::string type = "OperatorLt";
    public:
        OperatorLt(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt; }
};

class OperatorDiff : public OperatorLogic {
        std::string type = "OperatorDiff";
    public:
        OperatorDiff(): OperatorLogic(2){}
        bool test(Lnumerical* E1, Lnumerical* E2) const override;
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff; }
};


}



#endif // OPERATORLOGIC_H
