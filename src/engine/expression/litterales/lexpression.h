#ifndef LEXPRESSION_H
#define LEXPRESSION_H

#include "../../expression/expression.h"
#include <string>

namespace Engine {
/*  Création de la classe Lexpression encapsulant des expressions saisies dans la CommandLine.
 * Les expressions sont des littérales entre apostrophes.
*/
class Lexpression: public Expression, public ExplicitEval
{
    std::string expression; //attribut expression de type string
public:
    Lexpression(const std::string s): Expression("Lexpression"), expression(s){};//constructeur de la classe initialisant l'attribut expression et son type "LExpression"
    Lexpression* setLatom(const std::string s);
    std::string getValue() const {return expression;} //méthode renvoyant la valeur de l'attribut.
    void eval() override; //redéclaration de la méthode virtuelle héritée de Expression.
    std::string const toString() const override{return "'"+expression+"'";} //implémentation de l'affichage spécifié pour une littérale expression. Définition de la méthode héritée de Expression.
    Expression* getCopy() const override {return new Lexpression(expression);} //retourne une copie de l'instance, définition de la méthode héritée de Expression.
    void explicitEval() override; //évaluation d'un expression, définition non inline, méthode héritée de Expression.
    ~Lexpression() = default;
};
}
#endif // LEXPRESSION_H
