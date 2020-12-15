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
    void registerActionBinary(std::string type1,std::string type2,ActionBinary* a);
    void executeOpe(vector<Expression*> e);
};

class ActionBinary{
public:
    virtual Expression* executeActionBinary(Expression* L1, Expression* L2) = 0;
};


//Définitions classes opérateurs binaires
class OperatorPLUS : public OperatorAritBinary {
    public:
        OperatorPLUS();
        const std::string toString() const override{ return "+"; }
        Expression* getCopy() const override { return new OperatorPLUS; }
};

class OperatorMINUS : public OperatorAritBinary {
    public:
        OperatorMINUS();
        const std::string toString() const override{ return "-"; }
        Expression* getCopy() const override { return new OperatorMINUS; }
};

class OperatorMUL : public OperatorAritBinary {
    public:
        OperatorMUL();
        const std::string toString() const override{ return "*"; }
        Expression* getCopy() const override { return new OperatorMUL; }
};

class OperatorDIV : public OperatorAritBinary {
    public:
        OperatorDIV();
        const std::string toString() const override{ return "/"; }
        Expression* getCopy() const override { return new OperatorDIV; }
};

class OperatorDIVINT : public OperatorAritBinary {
    public:
        OperatorDIVINT();
        const std::string toString() const override{ return "DIV"; }
        Expression* getCopy() const override { return new OperatorDIVINT; }
};

class OperatorMOD : public OperatorAritBinary {
    public:
        OperatorMOD();
        const std::string toString() const override{ return "MOD"; }
        Expression* getCopy() const override { return new OperatorMOD; }
};


//Définitions des ActionBinarys possibles avec les opérateurs binaires
//opératorPLUS
class SumIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SumIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SumIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SumRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SumRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

//OperatorMINUS
class SubIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SubIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SubIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SubRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class SubRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

//OperatorMUL
class MulIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class MulIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};


class MulIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class MulRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class MulRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

//OperatorDIV
class DivIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class DivIntReal : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class DivIntRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class DivRealRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

class DivRatRat : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

//OperatorDIVINT pour la division entière
class DivintIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};

//Operator MOD
class ModIntInt : public ActionBinary {
    Expression* executeActionBinary(Expression* L1,Expression* L2);
};
}


#endif // OperatorAritBinary_H
