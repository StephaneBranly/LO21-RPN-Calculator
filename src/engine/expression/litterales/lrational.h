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
protected:
    std::string type="Lrational";
public:
    Lrational(int n, int d):numerator(n),denominator(d){
        if (d==0)
            throw ComputerException("Error : dénominateur invalide.");
    };
    Lrational(Linteger& e1, Linteger& e2){
        numerator = e1.getValue();
        if (e2.getValue()==0) throw ComputerException("Error : dénominateur invalide.");
        denominator = e2.getValue();
    };
    void setRational(int n, int d);
    void setRational(Linteger& e1, Linteger& e2);
    double getValue() override {return numerator/denominator;}
//    Lrational* createCopy()const override{return new Lrational(*this);}
    std::string const toString() const override {
       return std::to_string(numerator) + "/" + std::to_string(denominator) ;
    }
    const std::string getType() const override { return this->type; }
    Expression* getCopy() const override { return new Lrational(numerator,denominator); }
    int getNumerator () {return numerator;}
    int getDenominator () {return denominator;}
    Expression* simplifyType() override;
};
}
#endif // LRATIONNELLE_H
