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
    Expression(const std::string type): type(type){};
    virtual void eval() = 0;
    virtual const std::string toString() const = 0;
    const std::string getType() const { return type; }
    virtual Expression* getCopy() const = 0;    
    virtual ~Expression() = default;
};

class ExplicitEval{
public:
    virtual void explicitEval() = 0;
};

class editString{
public:
    virtual const std::string toEditString() const = 0;
};

}
#endif // EXPRESSION_H
