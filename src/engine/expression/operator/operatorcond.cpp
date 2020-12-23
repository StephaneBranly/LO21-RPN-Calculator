#include "operatorcond.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lprogram.h"


// Execute a si condition est vraie
void::Engine::OperatorIFT::executeOpe(vector<Expression*> e){
    R1value* a=dynamic_cast<R1value*>(e[1]);

    if(a!=nullptr)
    {
        if(a->getValue()!=0)
        {
            ExplicitEval* toEval = dynamic_cast<ExplicitEval*>(e[0]);
            if(toEval!=nullptr)
                toEval->explicitEval();
            else
                e[0]->eval();
       }
    }
    else
        throw ComputerException(e[1]->toString()+" n'est pas le résultat d'un test logique...");
}

// Execute a si condition est vraie, b sinon
void::Engine::OperatorIFTE::executeOpe(vector<Expression*> e){
    R1value* a=dynamic_cast<R1value*>(e[2]);

    if(a!=nullptr)
    {
        Expression* exp = nullptr;
        if(a->getValue()!=0)
            exp = e[1];
        else
            exp = e[0];

        ExplicitEval* toEval = dynamic_cast<ExplicitEval*>(exp);
        if(toEval!=nullptr)
            toEval->explicitEval();
        else
            exp->eval();
    }
    else
        throw ComputerException(e[2]->toString()+" n'est pas le résultat d'un test logique...");
}

// boucle le tant que la condition est valide
void::Engine::OperatorWHILE::executeOpe(vector<Expression*> e){
    Stack& p = ComputerEngine::getInstance().getStack();

    R1value* a=dynamic_cast<R1value*>(e[1]);
    Expression* exp = e[0];
    ExplicitEval* toEval = dynamic_cast<ExplicitEval*>(exp);
    unsigned int boucle = 0;
    do
    {
        if(a!=nullptr)
        {
            if(a->getValue()!=0)
            {
                if(toEval!=nullptr)
                    dynamic_cast<ExplicitEval*>(exp->getCopy())->explicitEval();
                else
                    exp->getCopy()->eval();
                if(p.size()>0)
                    a = dynamic_cast<R1value*>(p.pop());
                else
                    throw ComputerException("Il manque la valeur du test logique.");
                boucle++;
            }
        }
        else
            throw ComputerException(e[1]->toString()+" n'est pas le résultat d'un test logique.");
    }while(boucle<deepLimit && a!=nullptr && a->getValue()!=0);

    if(boucle>=deepLimit) throw ComputerException("Limite de boucles atteinte.");
}






