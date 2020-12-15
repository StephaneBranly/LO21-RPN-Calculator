#ifndef LRATIONNELLE_H
#define LRATIONNELLE_H
#include "linteger.h"
#include "../../exception/CompException.h"

namespace Engine {
class Lrational  : public Lnumerical
{
    int numerator;
    int denominator;
    int PGCD(int a, int b);
public:
    Lrational(int n, int d);
    Lrational(Linteger& e1, Linteger& e2);
    void setRational(int n, int d);
    void setRational(Linteger& e1, Linteger& e2);
    double getValue() override {return numerator/denominator;}
    std::string const toString() const override {
       return std::to_string(numerator) + "/" + std::to_string(denominator) ;
    }
    Expression* getCopy() const override { return new Lrational(numerator,denominator); }
    int getNumerator () {return numerator;}
    int getDenominator () {return denominator;}
    Expression* simplifyType() override;
};
}
#endif // LRATIONNELLE_H
