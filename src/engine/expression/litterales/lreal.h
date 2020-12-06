#ifndef LREELLE_H
#define LREELLE_H
#include "lnumerical.h"
#include <string>

namespace Engine {
class Lreal : public Lnumerical
{
    float real;
protected:
    std::string type="Lreal";
public:
    Lreal()=default;
    Lreal* setReal(float r);
//    LReal* createCopy()const override{return new LReal(*this);}
    Lreal* createExpressionFromString(const std::string s) override;
    bool isSameType(const std::string s) const override;
    std::string const toString()const override{return std::to_string(real);}
};
}
#endif // LREELLE_H
