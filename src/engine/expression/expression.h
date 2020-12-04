#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stdio.h"

namespace Engine {
class Expression{//abstract class
private:
    static std::string type;
public:
    virtual Expression* CreateExpressionFromString(const std::string s) const = 0 ;
    virtual bool isSameType(const std::string s) const = 0;
    virtual void eval() = 0;
    virtual std::string toString() = 0;
    std::string getType(){ return type; }
    virtual ~Expression() = 0;
};
}
#endif // EXPRESSION_H
