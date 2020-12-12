#ifndef OPERATORSDEFINITION_H
#define OPERATORSDEFINITION_H

#include "operator.h"

namespace Engine {
class OperatorCLEAR : public Operator {
    size_t arrity=0;
    std::string type = "OperatorCLEAR";
public:
    size_t getArrity () const override { return arrity; }
    void executeOpe() override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "CLEAR"; }
    Expression* getCopy() const override { return new OperatorCLEAR; }
};

class OperatorSWAP : public Operator {
    size_t arrity=2;
    std::string type = "OperatorSWAP";
public:
    size_t getArrity () const override { return arrity; }
    void executeOpe() override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "SWAP"; }
    Expression* getCopy() const override { return new OperatorSWAP; }
};

class OperatorDROP : public Operator {
    size_t arrity=1;
    std::string type = "OperatorDROP";
public:
    size_t getArrity () const override { return arrity; }
    void executeOpe() override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "DROP"; }
    Expression* getCopy() const override { return new OperatorDROP; }
};

class OperatorDUP : public Operator {
    size_t arrity=1;
    std::string type = "OperatorDUP";
public:
    size_t getArrity () const override { return arrity; }
    void executeOpe() override;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "DUP"; }
    Expression* getCopy() const override { return new OperatorDUP; }
};

}

#endif // OPERATORSDEFINITION_H
