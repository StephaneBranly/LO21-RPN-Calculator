#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stdio.h"
#include <QDebug>
namespace Engine {
class Expression{
protected:
    std::string type="Expression";
public:
    //virtual Expression* createCopy(Expression* A){return A;}
//    virtual Expression* createCopy()const = 0;
    virtual void eval() = 0;
    virtual const std::string toString() const = 0;
    virtual const std::string getType() const { return this->type; }
    virtual Expression* getCopy() const = 0;
    Expression() = default;
    Expression(const std::string type): type(type){};
    virtual ~Expression(){};
};


}
#endif // EXPRESSION_H
