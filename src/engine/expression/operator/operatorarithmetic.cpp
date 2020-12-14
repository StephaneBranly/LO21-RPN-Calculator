#include "operatorarithmetic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"
#include "../litterales/lnumerical.h"


//Constructeurs des opérateurs
//opérateur +
Engine::OperatorPLUS::OperatorPLUS(): OperatorArithmetic("OperatorPLUS")
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new SumIntInt);
    registerAction("Linteger", "Lreal", new SumIntReal);
    registerAction("Lreal", "Linteger", new SumIntReal);
    registerAction("Lreal", "Lreal", new SumIntReal);
    registerAction("Linteger", "Lrational", new SumIntRat);
    registerAction("Lrational", "Linteger", new SumIntRat);
    registerAction("Lreal", "Lrational", new SumRealRat);
    registerAction("Lrational", "Lreal", new SumRealRat);
    registerAction("Lrational", "Lrational", new SumRatRat);
}

//opérateur -
Engine::OperatorMINUS::OperatorMINUS(): OperatorArithmetic("OperatorMOINS")
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new SubIntInt);
    registerAction("Linteger", "Lreal", new SubIntReal);
    registerAction("Lreal", "Linteger", new SubIntReal);
    registerAction("Lreal", "Lreal", new SubIntReal);
    registerAction("Linteger", "Lrational", new SubIntRat);
    registerAction("Lrational", "Linteger", new SubIntRat);
    registerAction("Lreal", "Lrational", new SubRealRat);
    registerAction("Lrational", "Lreal", new SubRealRat);
    registerAction("Lrational", "Lrational", new SubRatRat);
}

//opérateur *
Engine::OperatorMUL::OperatorMUL(): OperatorArithmetic("OperatorMUL")
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new MulIntInt);
    registerAction("Linteger", "Lreal", new MulIntReal);
    registerAction("Lreal", "Linteger", new MulIntReal);
    registerAction("Lreal", "Lreal", new MulIntReal);
    registerAction("Linteger", "Lrational", new MulIntRat);
    registerAction("Lrational", "Linteger", new MulIntRat);
    registerAction("Lreal", "Lrational", new MulRealRat);
    registerAction("Lrational", "Lreal", new MulRealRat);
    registerAction("Lrational", "Lrational", new MulRatRat);
}

//opérateur /
Engine::OperatorDIV::OperatorDIV(): OperatorArithmetic("OperatorDIV")
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new DivIntInt);
    registerAction("Linteger", "Lreal", new DivIntReal);
    registerAction("Lreal", "Linteger", new DivIntReal);
    registerAction("Lreal", "Lreal", new DivIntReal);
    registerAction("Linteger", "Lrational", new DivIntRat);
    registerAction("Lrational", "Linteger", new DivIntRat);
    registerAction("Lreal", "Lrational", new DivRealRat);
    registerAction("Lrational", "Lreal", new DivRealRat);
    registerAction("Lrational", "Lrational", new DivRatRat);
}

void Engine::OperatorArithmetic::registerAction(std::string type1, std::string type2, Action *a)
{
    tuple<string, string> t = make_tuple(type1,type2);
    opes.insert(make_pair(t,a));
}

void Engine::OperatorArithmetic::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1=e[0];
    Expression* L2=e[1];

    tuple<string,string> t = make_tuple(L1->getType(),L2->getType());
    if (opes.find(t) != opes.end())
    {
        p.push(dynamic_cast<Lnumerical*>(opes.at(t)->executeAction(L2,L1))->simplifyType());
    }
    else
    {
        throw ComputerException("Action "+toString()+" impossible entre "+L1->getType()+" et "+L2->getType());
    }
}

//Redéfinition de la méthode pour chaque action
//Operator +
Engine::Expression* Engine::SumIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()+dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SumIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()+dynamic_cast<Lnumerical*>(L2)->getValue()));
}


Engine::Expression* Engine::SumIntRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()+dynamic_cast<Lnumerical*>(L2)->getValue()*dynamic_cast<Lrational*>(L1)->getDenominator()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    return (new Lrational((dynamic_cast<Lrational*>(L2)->getNumerator()+dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::SumRealRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    if (L1->getType()=="Lrational")
        return (new Lreal((float)(dynamic_cast<Lrational*>(L1)->getNumerator()/(float)dynamic_cast<Lrational*>(L1)->getDenominator())+dynamic_cast<Lnumerical*>(L2)->getValue()));
    return (new Lreal((float)(dynamic_cast<Lrational*>(L2)->getNumerator()/(float)dynamic_cast<Lrational*>(L2)->getDenominator())+dynamic_cast<Lnumerical*>(L1)->getValue()));
}

Engine::Expression* Engine::SumRatRat::executeAction(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator()+dynamic_cast<Lrational*>(L2)->getNumerator()*dynamic_cast<Lrational*>(L1)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator -
Engine::Expression* Engine::SubIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()-dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SubIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()-dynamic_cast<Lnumerical*>(L2)->getValue()));
}


Engine::Expression* Engine::SubIntRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a-b*c,b)
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()-dynamic_cast<Lnumerical*>(L2)->getValue()*dynamic_cast<Lrational*>(L1)->getDenominator()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*b-a,b)
    return (new Lrational((dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()-dynamic_cast<Lrational*>(L2)->getNumerator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::SubRealRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2 réel (c), retourne ((a/b)-c)
    if (L1->getType()=="Lrational")
        return (new Lreal((float)(dynamic_cast<Lrational*>(L1)->getNumerator()/(float)dynamic_cast<Lrational*>(L1)->getDenominator())-dynamic_cast<Lnumerical*>(L2)->getValue()));
    //Si L1 réel (c), L2 rationnel (a/b), retourne (c-(a/b))
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()-((float)dynamic_cast<Lrational*>(L2)->getNumerator()/(float)dynamic_cast<Lrational*>(L2)->getDenominator())));
}

Engine::Expression* Engine::SubRatRat::executeAction(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator()-dynamic_cast<Lrational*>(L2)->getNumerator()*dynamic_cast<Lrational*>(L1)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator *
Engine::Expression* Engine::MulIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()*dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::MulIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lnumerical*>(L2)->getValue()));
}

Engine::Expression* Engine::MulIntRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a*c,b)
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lnumerical*>(L2)->getValue()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*a,b)
    return (new Lrational((dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getNumerator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::MulRealRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a*c/b)
    if (L1->getType()=="Lrational")
        return (new Lreal(((float)dynamic_cast<Lnumerical*>(L2)->getValue()*(float)dynamic_cast<Lrational*>(L1)->getNumerator())/(float)dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*a/b)
    return (new Lreal(((float)dynamic_cast<Lnumerical*>(L1)->getValue()*(float)dynamic_cast<Lrational*>(L2)->getNumerator())/(float)dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::MulRatRat::executeAction(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getNumerator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator /
Engine::Expression* Engine::DivIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Lrational(dynamic_cast<Linteger*>(L1)->getValue(),dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::DivIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()/dynamic_cast<Lnumerical*>(L2)->getValue()));
}


Engine::Expression* Engine::DivIntRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a,b*c)
    if (L1->getType()=="Lrational")
        return (new Lrational(dynamic_cast<Lrational*>(L1)->getNumerator(),(dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lnumerical*>(L2)->getValue())));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*b,a)
    return (new Lrational((dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()),dynamic_cast<Lrational*>(L2)->getNumerator()));
}

Engine::Expression* Engine::DivRealRat::executeAction(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a/(b*c))
    if (L1->getType()=="Lrational")
        return (new Lreal((float)dynamic_cast<Lrational*>(L1)->getNumerator()/((float)dynamic_cast<Lnumerical*>(L2)->getValue()*(float)dynamic_cast<Lrational*>(L1)->getDenominator())));
    //Si L1 entier (c), L2 rationnel (a/b), retourne ((c*b)/a)
    return (new Lreal(((float)dynamic_cast<Lnumerical*>(L1)->getValue()*(float)dynamic_cast<Lrational*>(L2)->getDenominator())/(float)dynamic_cast<Lrational*>(L2)->getNumerator()));
}

Engine::Expression* Engine::DivRatRat::executeAction(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getNumerator();
    return (new Lrational(num,den));
}
