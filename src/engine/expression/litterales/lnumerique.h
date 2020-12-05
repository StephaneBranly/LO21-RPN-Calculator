#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include "expression.h"

namespace Engine {
class Lnumerique : public Expression
{
public:
    Lnumerique();
    void eval(); //les sous classes héritent de l'interface et du comportement
};
}
#endif // LNUMERIQUE_H
