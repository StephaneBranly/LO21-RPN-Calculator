#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include "stdio.h"

namespace Engine {
class Expression{//abstract class
public:
    virtual Expression* CreateExpressionFromString(const std::string s) const = 0 ;
    virtual bool isSameType(const std::string s) const = 0;
    //création d'une expression en fonction de son type
    //reconnaissance de type dans les sous-classes.
    virtual void afficher(std::ostream& f = std::cout) const = 0;
    //définition retardée au niveau des sous classes
    virtual void eval() = 0;
    virtual std::string toString ();
    virtual ~Expression();
};
}
#endif // EXPRESSION_H
