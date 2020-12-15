#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include <string>
#include "../expression.h"

namespace Engine {
class Lnumerical : public Expression
{
public:
    Lnumerical(const std::string type): Expression(type){}
    void eval(); //les sous classes héritent de l'interface et du comportement
    virtual double getValue() = 0;
    virtual Expression* simplifyType() = 0;
};
}
#endif // LNUMERIQUE_H
