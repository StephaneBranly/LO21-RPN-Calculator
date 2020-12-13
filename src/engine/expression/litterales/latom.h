#ifndef LATOM_H
#define LATOM_H
#include "../../expression/expression.h"
#include <string>

namespace Engine {
class Latom : public Expression
{
    std::string atom;
protected:
    std::string type="Latom";
public:
    Latom(const std::string s): atom(s){};
    Latom(const Latom&);
    Latom* setLatom(const std::string s);
    std::string getValue() const {return atom;}
    const std::string getType() const override { return this->type; }
    void eval() override;
    const std::string toString() const override{return atom;}
    Expression* getCopy() const override { return new Latom(atom); }
};
}
#endif // LATOM_H

