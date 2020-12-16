#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerical.h"
#include <string>

namespace Engine {
class Linteger : public Lnumerical, public R1value
{
    int value;
public:
    Linteger(const std::string s);
    Linteger(const Linteger&);
    Linteger(const int v): Lnumerical("Linteger"), value(v){};
    Linteger* setLinteger(int v);
    double getValue() override {return value;}
    std::string const toString() const override{ return std::to_string(value); }
    Expression* getCopy() const override { return new Linteger(value); }
    Expression* simplifyType () override { return this; }
};
}
#endif // LENTIERE_H
