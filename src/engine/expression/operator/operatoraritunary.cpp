#include "operatoraritunary.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"
#include "../litterales/lnumerical.h"


void Engine::OperatorAritUnary::registerActionUnary(std::string type, ActionUnary *a)
{
    opes.insert(make_pair(type,a));
}

void Engine::OperatorAritUnary::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L=e[0];
    string t = L->getType();
    if (opes.find(t) != opes.end())
    {
        p.push(dynamic_cast<Lnumerical*>(opes.at(t)->executeActionUnary(L))->simplifyType());
    }
    else
    {
        throw ComputerException("Action "+toString()+" impossible avec "+L->getType());
    }
}

//Constructeurs des opérateurs unaires
//opéteur NEG
Engine::OperatorNEG::OperatorNEG(): OperatorAritUnary("OperatorNEG")
{
    registerActionUnary("Linteger", new NegInt);
    registerActionUnary("Lreal", new NegReal);
    registerActionUnary("Lrational", new NegRat);
}

//Opérateur NUM
Engine::OperatorNUM::OperatorNUM(): OperatorAritUnary("OperatorNUM")
{
    registerActionUnary("Linteger", new NumInt);
    registerActionUnary("Lrational", new NumRat);
}

//Opérateur DEN
Engine::OperatorDEN::OperatorDEN(): OperatorAritUnary("OperatorDEN")
{
    registerActionUnary("Linteger", new DenInt);
    registerActionUnary("Lrational", new DenRat);
}

//Redéfinition de la méthode pour chaque ActionUnary
//Opérator NEG
Engine::Expression* Engine::NegInt::executeActionUnary(Expression* L)
{
    return (new Linteger(-1*dynamic_cast<Linteger*>(L)->getValue()));
}

Engine::Expression* Engine::NegReal::executeActionUnary(Expression* L)
{
    return (new Lreal(-1.0*dynamic_cast<Lreal*>(L)->getValue()));
}

Engine::Expression* Engine::NegRat::executeActionUnary(Expression* L)
{
    return (new Lrational(-1*dynamic_cast<Lrational*>(L)->getNumerator(), dynamic_cast<Lrational*>(L)->getDenominator()));
}

//Opérateur NUM
Engine::Expression* Engine::NumInt::executeActionUnary(Expression* L)
{
    return (new Linteger(dynamic_cast<Linteger*>(L)->getValue()));
}

Engine::Expression* Engine::NumRat::executeActionUnary(Expression* L)
{
    return (new Linteger(dynamic_cast<Lrational*>(L)->getNumerator()));
}

//Opérateur DEN
Engine::Expression* Engine::DenInt::executeActionUnary(Expression* L)
{
    return (new Linteger(1));
}

Engine::Expression* Engine::DenRat::executeActionUnary(Expression* L)
{
    return (new Linteger(dynamic_cast<Lrational*>(L)->getDenominator()));
}
