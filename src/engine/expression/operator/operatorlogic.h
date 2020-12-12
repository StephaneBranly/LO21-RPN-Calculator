#ifndef OPERATORLOGIC_H
#define OPERATORLOGIC_H

#include "operator.h"
#include <map>
#include <tuple>

namespace Engine{

class Action2{
   public:
    virtual Expression* executeAction(Expression* L1, Expression* L2) = 0;
    //virtual Expression* executeAction(Expression* L1) = 0;
};

//OperatorAnd
class AndIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class AndIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class AndIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class AndRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class AndRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class AndRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
//OperatorOr
class OrIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class OrIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class OrIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class OrRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class OrRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class OrRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

//OperatorNot

/*class NotInt:public Action2{
    Expression* executeAction(Expression* L1);
};

class NottReal:public Action2{
    Expression* executeAction(Expression* L1);
};

class NotRat:public Action2{
    Expression* executeAction(Expression* L1);
};*/


//OperatorEq
class EqIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class EqIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class EqIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class EqRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class EqRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class EqRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};


//OperatorGeq

class GeqIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class GeqIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class GeqIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class GeqRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class GeqRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class GeqRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};


//OperatorLeq
class LeqIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class LeqIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class LeqIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};


class LeqRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class LeqRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class LeqRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

//OperatorGt
class GtIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class GtIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class GtIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class GtRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class GtRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class GtRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

//OperatorLt
class LtIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class LtIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class LtIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class LtRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class LtRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class LtRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

//OperatorDiff
class DiffIntInt:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class DiffIntReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class DiffIntRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};

class DiffRatRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class DiffRealRat:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class DiffRealReal:public Action2{
    Expression* executeAction(Expression* L1, Expression* L2);
};
class OperatorLogic :public Operator
{
private:
    std::map<std::tuple<std::string,std::string>,Action2*> op;
public:
    void registerAction2(std::string type1,std::string type2,Action2* a);
    //void registerAction3(std::string type1,Action2* a);
    virtual size_t getArrity () const =0;
    void executeOpe();
};
class OperatorAnd : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorAnd";
    public:
        OperatorAnd();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "AND"; }
        Expression* getCopy() const override { return new OperatorAnd; }
};

class OperatorOr : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorOr";
    public:
        OperatorOr();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "OR"; }
        Expression* getCopy() const override { return new OperatorOr; }
};

class OperatorNot : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorNot";
    public:
        OperatorNot();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "NOT"; }
        Expression* getCopy() const override { return new OperatorNot; }
};

class OperatorEq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorEq";
    public:
        OperatorEq();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "=="; }
        Expression* getCopy() const override { return new OperatorEq; }
};

class OperatorGeq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorGeq";
    public:
        OperatorGeq();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">="; }
        Expression* getCopy() const override { return new OperatorGeq; }
};

class OperatorLeq : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorLeq";
    public:
        OperatorLeq();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "=<"; }
        Expression* getCopy() const override { return new OperatorLeq; }
};
class OperatorGt : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorGt";
    public:
        OperatorGt();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return ">"; }
        Expression* getCopy() const override { return new OperatorGt; }
};

class OperatorLt : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorLt";
    public:
        OperatorLt();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "<"; }
        Expression* getCopy() const override { return new OperatorLt; }
};

class OperatorDiff : public OperatorLogic {
        size_t arrity=2;
        std::string type = "OperatorDiff";
    public:
        OperatorDiff();
        size_t getArrity () const override { return arrity; }
        const std::string getType() const override { return this->type; }
        const std::string toString() const override{ return "!="; }
        Expression* getCopy() const override { return new OperatorDiff; }
};
}



#endif // OPERATORLOGIC_H
