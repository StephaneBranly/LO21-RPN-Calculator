#ifndef LRATIONNELLE_H
#define LRATIONNELLE_H
#include "linteger.h"

namespace Engine {


class Lrational  : public Lnumerical
{
    int numerateur;
    int denominateur;
    void simplify();
public:
    Lrational(int n, int d):numerateur(n),denominateur(d){};
    void setRational(int n, int d);
    void setRational(Linteger& e1, Linteger& e2);
    //void display();
    Lrational* createExpressionFromString(const std::string s) const override {};
    Lrational* createCopy()const override{return new Lrational(*this);}
    bool isSameType(const std::string s) const override{};
    //à définir
    std::string const toString() const override {
       return std::to_string(numerateur) + "/" + std::to_string(denominateur) ;
    }
};
}
#endif // LRATIONNELLE_H
