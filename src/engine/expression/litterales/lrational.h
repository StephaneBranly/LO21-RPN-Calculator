#ifndef LRATIONNELLE_H
#define LRATIONNELLE_H
#include "linteger.h"


namespace Engine {
class Lrational  : public Lnumerical
{
    int numerateur;
    int denominateur;
    void simplify();
protected:
    std::string type="Lrational";
public:
    Lrational(int n, int d):numerateur(n),denominateur(d){};
    void setRational(int n, int d);
    void setRational(Linteger& e1, Linteger& e2);
//    Lrational* createCopy()const override{return new Lrational(*this);}
//    bool isSameType(const std::string s) const override{};
    std::string const toString() const override {
       return std::to_string(numerateur) + "/" + std::to_string(denominateur) ;
    }
    const std::string getType() const override { return this->type; }
};
}
#endif // LRATIONNELLE_H
