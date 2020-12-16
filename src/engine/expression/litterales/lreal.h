#ifndef LREELLE_H
#define LREELLE_H
#include "lnumerical.h"
#include <string>
#include "linteger.h"

namespace Engine {
class Lreal : public Lnumerical, public R1value
{
    float real;
public:
    Lreal(const std::string s);
    Lreal(float r): Lnumerical("Lreal"),real(r){};
    Lreal* setReal(float r);
    double getValue() override {return real;}
//    LReal* createCopy()const override{return new LReal(*this);}
    std::string const toString()const override{return std::to_string(real);}
    Expression* getCopy() const override { return new Lreal(real); }
    Expression* simplifyType() override;
};
}
#endif // LREELLE_H
