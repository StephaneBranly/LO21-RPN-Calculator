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
    Lreal(const std::string s);
    Lreal* setReal(float r);
//    LReal* createCopy()const override{return new LReal(*this);}
    std::string const toString()const override{return std::to_string(real);}
    const std::string getType() const override { return this->type; }
};
}
#endif // LREELLE_H
