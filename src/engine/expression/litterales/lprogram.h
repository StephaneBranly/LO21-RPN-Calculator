#ifndef LPROGRAM_H
#define LPROGRAM_H


#include "../../expression/expression.h"
#include <string>
#include <list>
namespace Engine {
class Lprogram : public Expression, public ExplicitEval
{
    std::list<Expression*> content;
protected:
    std::string type="Lprogram";
public:
    Lprogram(){};
    Lprogram(const Lprogram&);
    const std::string getType() const override { return this->type; }
    void eval() override;
    const std::string toString() const override;
    Expression* getCopy() const override { return new Lprogram(*this); }
    void explicitEval() override;
    void push_back(Expression* e){ content.push_back(e); }
};
}

#endif // LPROGRAM_H
