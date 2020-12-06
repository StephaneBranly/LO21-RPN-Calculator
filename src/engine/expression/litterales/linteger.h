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
    Linteger* setLinteger(int v);
    int getvalue(){return value;}
//    Linteger* createCopy()const override{return new Linteger(*this);}
    std::string const toString() const override{ return std::to_string(value); }
};
}
#endif // LENTIERE_H
