#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include <string>
#include "../expression.h"

namespace Engine {
class Lnumerical : public Expression
{
public:
    Lnumerical();
    void eval(); //les sous classes héritent de l'interface et du comportement
    //virtual Expression* createExpressionFromString(const std::string s) const=0;
};
}
#endif // LNUMERIQUE_H
