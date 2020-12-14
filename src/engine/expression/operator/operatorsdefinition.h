#ifndef OPERATORSDEFINITION_H
#define OPERATORSDEFINITION_H

#include "operator.h"

namespace Engine {
class OperatorCLEAR : public Operator {
    std::string type = "OperatorCLEAR";
public:
    OperatorCLEAR(): Operator(0){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "CLEAR"; }
    Expression* getCopy() const override { return new OperatorCLEAR; }
};

class OperatorSWAP : public Operator {
    std::string type = "OperatorSWAP";
public:
    OperatorSWAP(): Operator(2){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "SWAP"; }
    Expression* getCopy() const override { return new OperatorSWAP; }
};

class OperatorDROP : public Operator {
    std::string type = "OperatorDROP";
public:
    OperatorDROP(): Operator(1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "DROP"; }
    Expression* getCopy() const override { return new OperatorDROP; }
};

class OperatorDUP : public Operator {
    std::string type = "OperatorDUP";
public:
    OperatorDUP(): Operator(1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "DUP"; }
    Expression* getCopy() const override { return new OperatorDUP; }
};


class OperatorEVAL : public Operator {
    std::string type = "OperatorEVAL";
public:
    OperatorEVAL(): Operator(1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "EVAL"; }
    Expression* getCopy() const override { return new OperatorEVAL; }
};

class OperatorSTO : public Operator {
    std::string type = "OperatorSTO";
public:
    OperatorSTO(): Operator(2){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "STO"; }
    Expression* getCopy() const override { return new OperatorSTO; }
};


class OperatorFORGET : public Operator {
    std::string type = "OperatorFORGET";
public:
    OperatorFORGET(): Operator(1){}
    void executeOpe(vector<Expression*> e) override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "FORGET"; }
    Expression* getCopy() const override { return new OperatorFORGET; }
};
}

#endif // OPERATORSDEFINITION_H
