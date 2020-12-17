#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include <string>
#include "../expression.h"

namespace Engine {
class Lnumerical : public Expression
{
public:
    Lnumerical();
    Lnumerical(const std::string type): Expression(type){}
    void eval(); //les sous classes héritent de l'interface et du comportement
    virtual Expression* simplifyType() = 0;
};

class R1value
{
public:
        virtual double getValue() = 0;
};
}
#endif // LNUMERIQUE_H
