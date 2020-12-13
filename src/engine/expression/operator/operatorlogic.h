#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"

namespace Engine{

class OperatorLogic :public Operator
{
public:
    virtual size_t getArrity () const =0;
    void executeOpe();
    virtual bool test(Expression* E1, Expression* E2) const=0;
};


class OperatorAnd : public OperatorLogic {
        size_t arrity=2;
        std::string type = "AND";
    public:

        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd; }
};

class OperatorOr : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorOr";
    public:

        bool test(Expression* E1, Expression* E2) const override;        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr; }
};

class OperatorNot : public OperatorLogic {
        size_t arrity=1;
        std::string type = "OperatorNot";
    public:

        bool test(Expression* E1, Expression* E2=nullptr) const override ;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot; }
};

class OperatorEq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorEq";
    public:

        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "="; }
        Expression* getCopy() const override { return new OperatorEq; }
};

class OperatorGeq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorGeq";
    public:


        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq; }
};

class OperatorLeq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorLeq";
    public:

        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq; }
};
class OperatorGt : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorGt";
    public:

       bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt; }
};

class OperatorLt : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorLt";
    public:

        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt; }
};

class OperatorDiff : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorDiff";
    public:

        bool test(Expression* E1, Expression* E2) const override;
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff; }
};


}



#endif // OPERATORLOGIC_H
