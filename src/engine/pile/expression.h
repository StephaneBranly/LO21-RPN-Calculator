#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace Engine {
class Expression //iterator à ajouter
{
    Operande** op; //une expression est une suite d'opérandes
    friend class ExpressionManager; //classe responsable du cycle de vie d'une expression
    Expression():op(nullptr){};
    ~Expression(){delete[] op;}

public:
    class iterator{};//parcourt les operandes.
};
}
#endif // EXPRESSION_H
