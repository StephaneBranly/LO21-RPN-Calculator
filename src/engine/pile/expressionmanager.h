#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H
#include <string>
#include "expression.h"
#include "CompException.h"

namespace  Engine{
class ExpressionManager{ //contient toutes les expressions, et le cycle de vie d'une expression
//Singleton + ITERATOR : choisir le mode d'implémentation
    Expression** exps = nullptr; //pointe sur un tableau d'expression
    size_t nb = 0; //nombre d'adresse stockées
    size_t nbMax = 0; //capacité max du tableau

    ExpressionManager()=default;
    ~ExpressionManager();
    struct Handler {
        ExpressionManager* instance= nullptr;
        Handler() = default ;
        ~Handler(){delete instance; }

    };
    static Handler handler;

public:
    Expression& addExpression(Expression& e);
    /*est ce qu expressionmanage peut ajouter une expression, c'est à dire
en créer une nouvelle? On a aussi les Varmanager et Progmanager qui vont gérer
les nouvelles expressions, et le reste des expressions sont prédéfinies?*/
    void removeExpression(Expression& e);
    void agrandissementCapacite();
    static ExpressionManager& getInstance();
    void libereinstance();
};
}
/*Question :
 * avons nous besoin d'un iterator pour cette classe?
 * Puisqu'on aura des iterator pour varmanager et prog manager?
*/
#endif // EXPRESSIONMANAGER_H
