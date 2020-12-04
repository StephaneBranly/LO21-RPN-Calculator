#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stdio.h"

namespace Engine {

class Expression{
private:
    static std::string type;
public:
    virtual Expression* CreateExpressionFromString(const std::string s) const = 0 ;
    virtual Expression* createCopy(Expression* e){ return e; };
    virtual bool isSameType(const std::string s) const = 0;
    virtual void eval() = 0;
    virtual std::string toString() const = 0;
    std::string getType() const{ return type; }

    Expression() = default;

    virtual ~Expression();
};

}
#endif // EXPRESSION_H
