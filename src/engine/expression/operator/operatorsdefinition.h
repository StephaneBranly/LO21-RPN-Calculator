#ifndef OPERATORSDEFINITION_H
#define OPERATORSDEFINITION_H

#include "operator.h"

namespace Engine {
class OperatorCLEAR : public Operator {
public:
    OperatorCLEAR(): Operator("OperatorCLEAR",0){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "CLEAR"; }
    Expression* getCopy() const override { return new OperatorCLEAR; }
};

class OperatorSWAP : public Operator {
public:
    OperatorSWAP(): Operator("OperatorSWAP",2){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "SWAP"; }
    Expression* getCopy() const override { return new OperatorSWAP; }
};

class OperatorDROP : public Operator {
public:
    OperatorDROP(): Operator("OperatorDROP",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "DROP"; }
    Expression* getCopy() const override { return new OperatorDROP; }
};

class OperatorDUP : public Operator {
public:
    OperatorDUP(): Operator("OperatorDUP",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "DUP"; }
    Expression* getCopy() const override { return new OperatorDUP; }
};


class OperatorEVAL : public Operator {
public:
    OperatorEVAL(): Operator("OperatorEVAL",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "EVAL"; }
    Expression* getCopy() const override { return new OperatorEVAL; }
};

class OperatorSTO : public Operator {
public:
    OperatorSTO(): Operator("OperatorSTO",2){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "STO"; }
    Expression* getCopy() const override { return new OperatorSTO; }
};


class OperatorFORGET : public Operator {
public:
    OperatorFORGET(): Operator("OperatorFORGET",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "FORGET"; }
    Expression* getCopy() const override { return new OperatorFORGET; }
};

class OperatorTYPE : public Operator {
public:
    OperatorTYPE(): Operator("OperatorTYPE",1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string toString() const override{ return "TYPE"; }
    Expression* getCopy() const override { return new OperatorTYPE; }
};
}

#endif // OPERATORSDEFINITION_H
