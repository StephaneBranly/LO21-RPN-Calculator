#ifndef LREELLE_H
#define LREELLE_H
#include "lnumerical.h"
#include <string>
#include "linteger.h"

namespace Engine {

// Lreal, est une Lnumerical dans le domaine R1 (herite de R1 value)
class Lreal : public Lnumerical, public R1value
{
    double real;
public:
    Lreal(const std::string s);
    Lreal(double r): Lnumerical("Lreal"),real(r){};
    Lreal* setReal(double r);
    double getValue() override {return real;}
    std::string const toString()const override{return std::to_string(real);}
    Expression* getCopy() const override { return new Lreal(real); }
    Expression* simplifyType() override;
    ~Lreal() = default;
};
}
#endif // LREELLE_H
