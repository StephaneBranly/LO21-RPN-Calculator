#ifndef OPERATORSDEFINITION_H
#define OPERATORSDEFINITION_H

#include "operator.h"

namespace Engine {
class OperatorCLEAR : public Operator {
    size_t arrity=0;
    std::string type = "OperatorCLEAR";
public:
    OperatorCLEAR()=default;
//    size_t getArrity () const override { return arrity; }
    void eval() override ;
    const std::string getType() const override { return this->type; }
    const std::string toString() const override{ return "CLEAR"; }
    Operator* getCopy() override { return new OperatorCLEAR; }
};
}

#endif // OPERATORSDEFINITION_H
