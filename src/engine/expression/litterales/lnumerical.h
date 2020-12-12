#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include <string>
#include "../expression.h"

namespace Engine {
class Lnumerical : public Expression
{
public:
    void eval(); //les sous classes héritent de l'interface et du comportement
    virtual double getValue() =0;
};
}
#endif // LNUMERIQUE_H
