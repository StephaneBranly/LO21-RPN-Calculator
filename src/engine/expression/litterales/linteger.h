#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerical.h"
#include "../../exception/CompException.h"
#include <string>

namespace Engine {
//Classe Linteger : encapsule des objets de type integer.
class Linteger : public Lnumerical, public R1value
{
    int value; //attribut de classe de type int.
public:
    Linteger(const std::string s); //constructeur prenant en paramètre un string venant de la CommandLine.
    Linteger(const Linteger&); //on peut construire un Linteger à partir d'un autre.
    Linteger(const int v): Lnumerical("Linteger"), value(v){};//construction et initialisation de l'attribut, et de son type.
    Linteger* setLinteger(int v);
    double getValue() override {return value;}
    std::string const toString() const override{ return std::to_string(value); }
    Expression* getCopy() const override { return new Linteger(value); }
    Expression* simplifyType () override { return this; }
};
}
#endif // LENTIERE_H
