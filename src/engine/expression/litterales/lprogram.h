#ifndef LPROGRAM_H
#define LPROGRAM_H


#include "../../expression/expression.h"
#include <string>
#include <list>
namespace Engine {

// Type Lprogram, stocker une liste d'expression
// Herite de ExpliciteEval correspond a une evaluation demandee par l'utilisateur (EVAL) ou par l'engine (execution de IFT,...)
// herite de editString qui permet de diffencier l'affichage de la valeur d'edition (ici car 3/5 et genere par 3 5 /)
class Lprogram : public Expression, public ExplicitEval,public editString
{
    std::list<Expression*> content;
public:
    Lprogram(): Expression("Lprogram"){};
    Lprogram(const Lprogram&);
    void eval() override;
    const std::string toString() const override;
    const std::string toEditString() const override;
    Expression* getCopy() const override { return new Lprogram(*this); }
    void explicitEval() override;
    void push_back(Expression* e){ content.push_back(e); }
};
}

#endif // LPROGRAM_H
