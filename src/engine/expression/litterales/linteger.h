#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerical.h"
#include <string>

namespace Engine {
class Linteger : public Lnumerical
{
    int value;
protected:
    std::string type="Linteger";
public:
    Linteger(const std::string s);
    Linteger(const Linteger&);
    Linteger(const int v): value(v){};
    Linteger* setLinteger(int v);
    double getValue() override {return value;}
//    Linteger* createCopy()const override{return new Linteger(*this);}
    std::string const toString() const override{ return std::to_string(value); }
    const std::string getType() const override { return this->type; }
    Expression* getCopy() const override { return new Linteger(value); }
    Expression* simplifyType () override { return this; }
};
}
#endif // LENTIERE_H
