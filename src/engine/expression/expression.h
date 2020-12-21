#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stdio.h"
#include <QDebug>
namespace Engine {

// Classe abstraite expression
// Dispose d'un type
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

// Classe permettant d'indiquer avec polymorphisme qu'une litterale peut etre evaluee explicitement (EVAL, lors d'un IFTE...)
class ExplicitEval{
public:
    virtual void explicitEval() = 0;
};

// Classe permettant d'indiquer avec polymorphisme qu'une litterale a un nom d'affichage different de celui de generation (3/5 se genere avec 3 5 /)
class editString{
public:
    virtual const std::string toEditString() const = 0;
};

}
#endif // EXPRESSION_H
