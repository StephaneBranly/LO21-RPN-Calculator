#ifndef LPROGRAM_H
#define LPROGRAM_H


#include "../../expression/expression.h"
#include <string>
#include <list>
namespace Engine {
class Lprogram : public Expression, public ExplicitEval
{
    std::list<Expression*> content;
public:
    Lprogram(): Expression("Lprogram"){};
    Lprogram(const Lprogram&);
    void eval() override;
    const std::string toString() const override;
    Expression* getCopy() const override { return new Lprogram(*this); }
    void explicitEval() override;
    void push_back(Expression* e){ content.push_back(e); }
};
}

#endif // LPROGRAM_H
