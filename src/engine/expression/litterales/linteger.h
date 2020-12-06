#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerical.h"
#include <string>

namespace Engine {
class Linteger : public Lnumerical
{
    int value;

public:
    //Linteger();
    Linteger(const Linteger&);
    Linteger* setLinteger(int v);
    int getvalue(){return value;}
//    Linteger* createCopy()const override{return new Linteger(*this);}
    Linteger* createExpressionFromString(const std::string s) override;
    bool isSameType(const std::string s) const override;
    std::string const toString() const override{ return std::to_string(value); }
};
}
#endif // LENTIERE_H
