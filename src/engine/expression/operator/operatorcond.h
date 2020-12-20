#ifndef OPERATORCOND_H
#define OPERATORCOND_H

#include "operator.h"

using namespace std;

namespace Engine{


class OperatorIFT : public Operator {
    public:
        OperatorIFT():Operator("OperatorIFT",2){}
        const std::string toString() const override{ return "IFT"; }
        Expression* getCopy() const override { return new OperatorIFT; }
        void executeOpe(vector<Expression*> e) override;
    };

class OperatorIFTE : public Operator {
    public:
        OperatorIFTE():Operator("OperatorIFTE",3){}
        const std::string toString() const override{ return "IFTE"; }
        Expression* getCopy() const override { return new OperatorIFTE; }
        void executeOpe(vector<Expression*> e) override;
    };

class OperatorWHILE : public Operator {
private:
    unsigned int deepLimit = 1000;
    public:
        OperatorWHILE():Operator("OperatorWHILE",2){}
        void setDeepLimit(const unsigned int i){ deepLimit = i; }
        const std::string toString() const override{ return "WHILE"; }
        Expression* getCopy() const override { return new OperatorWHILE; }
        void executeOpe(vector<Expression*> e) override;
    };









}



#endif // OPERATORCOND_H
