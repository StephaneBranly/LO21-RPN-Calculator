#ifndef LREELLE_H
#define LREELLE_H
#include "lnumerique.h"

namespace Engine {


class LReelle  : public Lnumerique
{
    float reel;
public:
    LReelle();
    void setReel(float r);
    LReelle* createCopy()const{return new LReelle(*this);}
    LReelle* createExpressionFromString(const std::string s) const = 0 ;
};
}
#endif // LREELLE_H
