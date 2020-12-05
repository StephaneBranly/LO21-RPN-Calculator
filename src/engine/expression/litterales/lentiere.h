#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerique.h"
#include <string>

namespace Engine {
class Lentiere : public Lnumerique
{
    int value;

public:
    Lentiere();
    void setLentiere(int v);
    int getvalue(){return value;}
    Lentiere* createCopy()const{return new Lentiere(*this);}
    Lentiere* createExpressionFromString(const std::string s);
};
}
#endif // LENTIERE_H
