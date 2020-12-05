#ifndef LRATIONNELLE_H
#define LRATIONNELLE_H
#include "lentiere.h"

namespace Engine {


class Lrationnelle  : public Lnumerique
{
    int numerateur;
    int denominateur;
    void simplification();
public:
    Lrationnelle();
    void setRationelle(int n, int d);
    void setrationnelle(Lentiere& e1, Lentiere& e2);
    void afficher();
    Lrationnelle* createCopy()const{return new Lrationnelle(*this);}
    Lrationnelle* createExpressionFromString(const std::string s) const = 0 ;

};
}
#endif // LRATIONNELLE_H
