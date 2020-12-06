#ifndef LREELLE_H
#define LREELLE_H
#include "lnumerical.h"
#include <string>

namespace Engine {
class LReal : public Lnumerical
{
    float real;
public:
    LReal();
    LReal* setReal(float r);
    LReal* createCopy()const override{return new LReal(*this);}
    LReal* createExpressionFromString(const std::string s) const override {
        //à définir
    };
    bool isSameType(const std::string s) const override{
        //à définir
    };
    std::string const toString()const override{return std::to_string(real);}
};
}
#endif // LREELLE_H
