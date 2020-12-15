#ifndef LEXPRESSION_H
#define LEXPRESSION_H

#include "../../expression/expression.h"
#include <string>

namespace Engine {
class Lexpression: public Expression, public ExplicitEval
{
    std::string expression;
public:
    Lexpression(const std::string s): Expression("Lexpression"), expression(s){};
    Lexpression* setLatom(const std::string s);
    std::string getValue(){return expression;}
    void eval() override;
    std::string const toString() const override{return "'"+expression+"'";}
    Expression* getCopy() const override { return new Lexpression(expression); }
    void explicitEval() override;
};
}
#endif // LEXPRESSION_H
