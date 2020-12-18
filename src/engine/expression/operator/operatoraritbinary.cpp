#include "operatoraritbinary.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"
#include "../litterales/lnumerical.h"
#include <math.h>


//Définition de registerActionBinary et executeOpe
void Engine::OperatorAritBinary::registerActionBinary(std::string type1, std::string type2, ActionBinary *a)
{
    tuple<string, string> t = make_tuple(type1,type2);
    opes.insert(make_pair(t,a));
}

void Engine::OperatorAritBinary::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1=e[0];
    Expression* L2=e[1];

    tuple<string,string> t = make_tuple(L1->getType(),L2->getType());
    if (opes.find(t) != opes.end())
    {
        p.push(dynamic_cast<Lnumerical*>(opes.at(t)->executeActionBinary(L2,L1))->simplifyType());
    }
    else
    {
        throw ComputerException("Action "+toString()+" impossible entre "+L1->getType()+" et "+L2->getType());
    }
}

//Destructeur des operateurs binaires
Engine::OperatorAritBinary::~OperatorAritBinary()
{
    for(auto it = opes.begin(); it!=opes.end(); ++it)
        delete (*it).second;
}

//Constructeurs des opérateurs binaire
//opérateur +
Engine::OperatorPLUS::OperatorPLUS(): OperatorAritBinary("OperatorPLUS")
{
    //9 ActionBinarys à implémenter
    registerActionBinary("Linteger", "Linteger", new SumIntInt);
    registerActionBinary("Linteger", "Lreal", new SumIntReal);
    registerActionBinary("Lreal", "Linteger", new SumIntReal);
    registerActionBinary("Lreal", "Lreal", new SumIntReal);
    registerActionBinary("Linteger", "Lrational", new SumIntRat);
    registerActionBinary("Lrational", "Linteger", new SumIntRat);
    registerActionBinary("Lreal", "Lrational", new SumRealRat);
    registerActionBinary("Lrational", "Lreal", new SumRealRat);
    registerActionBinary("Lrational", "Lrational", new SumRatRat);
}

//opérateur -
Engine::OperatorMINUS::OperatorMINUS(): OperatorAritBinary("OperatorMOINS")
{
    //9 ActionBinarys à implémenter
    registerActionBinary("Linteger", "Linteger", new SubIntInt);
    registerActionBinary("Linteger", "Lreal", new SubIntReal);
    registerActionBinary("Lreal", "Linteger", new SubIntReal);
    registerActionBinary("Lreal", "Lreal", new SubIntReal);
    registerActionBinary("Linteger", "Lrational", new SubIntRat);
    registerActionBinary("Lrational", "Linteger", new SubIntRat);
    registerActionBinary("Lreal", "Lrational", new SubRealRat);
    registerActionBinary("Lrational", "Lreal", new SubRealRat);
    registerActionBinary("Lrational", "Lrational", new SubRatRat);
}

//opérateur *
Engine::OperatorMUL::OperatorMUL(): OperatorAritBinary("OperatorMUL")
{
    //9 ActionBinarys à implémenter
    registerActionBinary("Linteger", "Linteger", new MulIntInt);
    registerActionBinary("Linteger", "Lreal", new MulIntReal);
    registerActionBinary("Lreal", "Linteger", new MulIntReal);
    registerActionBinary("Lreal", "Lreal", new MulIntReal);
    registerActionBinary("Linteger", "Lrational", new MulIntRat);
    registerActionBinary("Lrational", "Linteger", new MulIntRat);
    registerActionBinary("Lreal", "Lrational", new MulRealRat);
    registerActionBinary("Lrational", "Lreal", new MulRealRat);
    registerActionBinary("Lrational", "Lrational", new MulRatRat);
}

//opérateur /
Engine::OperatorDIV::OperatorDIV(): OperatorAritBinary("OperatorDIV")
{
    //9 ActionBinarys à implémenter
    registerActionBinary("Linteger", "Linteger", new DivIntInt);
    registerActionBinary("Linteger", "Lreal", new DivIntReal);
    registerActionBinary("Lreal", "Linteger", new DivIntReal);
    registerActionBinary("Lreal", "Lreal", new DivIntReal);
    registerActionBinary("Linteger", "Lrational", new DivIntRat);
    registerActionBinary("Lrational", "Linteger", new DivIntRat);
    registerActionBinary("Lreal", "Lrational", new DivRealRat);
    registerActionBinary("Lrational", "Lreal", new DivRealRat);
    registerActionBinary("Lrational", "Lrational", new DivRatRat);
}

// Operateur DIVINT
Engine::OperatorDIVINT::OperatorDIVINT(): OperatorAritBinary("OperatorDIVINT")
{
    registerActionBinary("Linteger", "Linteger", new DivintIntInt);
}

//Operateur MOD
Engine::OperatorMOD::OperatorMOD(): OperatorAritBinary("OperatorMOD")
{
    registerActionBinary("Linteger", "Linteger", new ModIntInt);
}

//Operator POW
Engine::OperatorPOW::OperatorPOW(): OperatorAritBinary("OperatorPOW")
{
    registerActionBinary("Linteger", "Linteger", new PowIntInt);
    registerActionBinary("Linteger", "Lreal", new PowRealInt);
    registerActionBinary("Linteger", "Lrational", new PowRatInt);

}

//Redéfinition de la méthode pour chaque ActionBinary
//Operator +
Engine::Expression* Engine::SumIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()+dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SumIntReal::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<R1value*>(L1)->getValue()+dynamic_cast<R1value*>(L2)->getValue()));
}


Engine::Expression* Engine::SumIntRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()+dynamic_cast<R1value*>(L2)->getValue()*dynamic_cast<Lrational*>(L1)->getDenominator()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    return (new Lrational((dynamic_cast<Lrational*>(L2)->getNumerator()+dynamic_cast<R1value*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::SumRealRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    if (L1->getType()=="Lrational")
        return (new Lreal((float)(dynamic_cast<Lrational*>(L1)->getNumerator()/(float)dynamic_cast<Lrational*>(L1)->getDenominator())+dynamic_cast<R1value*>(L2)->getValue()));
    return (new Lreal((float)(dynamic_cast<Lrational*>(L2)->getNumerator()/(float)dynamic_cast<Lrational*>(L2)->getDenominator())+dynamic_cast<R1value*>(L1)->getValue()));
}

Engine::Expression* Engine::SumRatRat::executeActionBinary(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator()+dynamic_cast<Lrational*>(L2)->getNumerator()*dynamic_cast<Lrational*>(L1)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator -
Engine::Expression* Engine::SubIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()-dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SubIntReal::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<R1value*>(L1)->getValue()-dynamic_cast<R1value*>(L2)->getValue()));
}


Engine::Expression* Engine::SubIntRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a-b*c,b)
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()-dynamic_cast<R1value*>(L2)->getValue()*dynamic_cast<Lrational*>(L1)->getDenominator()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*b-a,b)
    return (new Lrational((dynamic_cast<R1value*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()-dynamic_cast<Lrational*>(L2)->getNumerator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::SubRealRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2 réel (c), retourne ((a/b)-c)
    if (L1->getType()=="Lrational")
        return (new Lreal((float)(dynamic_cast<Lrational*>(L1)->getNumerator()/(float)dynamic_cast<Lrational*>(L1)->getDenominator())-dynamic_cast<R1value*>(L2)->getValue()));
    //Si L1 réel (c), L2 rationnel (a/b), retourne (c-(a/b))
    return (new Lreal(dynamic_cast<R1value*>(L1)->getValue()-((float)dynamic_cast<Lrational*>(L2)->getNumerator()/(float)dynamic_cast<Lrational*>(L2)->getDenominator())));
}

Engine::Expression* Engine::SubRatRat::executeActionBinary(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator()-dynamic_cast<Lrational*>(L2)->getNumerator()*dynamic_cast<Lrational*>(L1)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator *
Engine::Expression* Engine::MulIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()*dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::MulIntReal::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<R1value*>(L1)->getValue()*dynamic_cast<R1value*>(L2)->getValue()));
}

Engine::Expression* Engine::MulIntRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a*c,b)
    if (L1->getType()=="Lrational")
        return (new Lrational((dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<R1value*>(L2)->getValue()),dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*a,b)
    return (new Lrational((dynamic_cast<R1value*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getNumerator()),dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::MulRealRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a*c/b)
    if (L1->getType()=="Lrational")
        return (new Lreal(((float)dynamic_cast<R1value*>(L2)->getValue()*(float)dynamic_cast<Lrational*>(L1)->getNumerator())/(float)dynamic_cast<Lrational*>(L1)->getDenominator()));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*a/b)
    return (new Lreal(((float)dynamic_cast<R1value*>(L1)->getValue()*(float)dynamic_cast<Lrational*>(L2)->getNumerator())/(float)dynamic_cast<Lrational*>(L2)->getDenominator()));
}

Engine::Expression* Engine::MulRatRat::executeActionBinary(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getNumerator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    return (new Lrational(num,den));
}

//Operator /
Engine::Expression* Engine::DivIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lrational(dynamic_cast<Linteger*>(L1)->getValue(),dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::DivIntReal::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<R1value*>(L1)->getValue()/dynamic_cast<R1value*>(L2)->getValue()));
}

Engine::Expression* Engine::DivIntRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a,b*c)
    if (L1->getType()=="Lrational")
        return (new Lrational(dynamic_cast<Lrational*>(L1)->getNumerator(),(dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<R1value*>(L2)->getValue())));
    //Si L1 entier (c), L2 rationnel (a/b), retourne (c*b,a)
    return (new Lrational((dynamic_cast<R1value*>(L1)->getValue()*dynamic_cast<Lrational*>(L2)->getDenominator()),dynamic_cast<Lrational*>(L2)->getNumerator()));
}

Engine::Expression* Engine::DivRealRat::executeActionBinary(Expression* L1,Expression* L2)
{
    //Test d'abord si c'est L1 le rationnel, sinon c'est L2
    //Si L1 rationnel(a/b), L2(c), retourne (a/(b*c))
    if (L1->getType()=="Lrational")
        return (new Lreal((float)dynamic_cast<Lrational*>(L1)->getNumerator()/((float)dynamic_cast<R1value*>(L2)->getValue()*(float)dynamic_cast<Lrational*>(L1)->getDenominator())));
    //Si L1 entier (c), L2 rationnel (a/b), retourne ((c*b)/a)
    return (new Lreal(((float)dynamic_cast<R1value*>(L1)->getValue()*(float)dynamic_cast<Lrational*>(L2)->getDenominator())/(float)dynamic_cast<Lrational*>(L2)->getNumerator()));
}

Engine::Expression* Engine::DivRatRat::executeActionBinary(Expression* L1,Expression* L2)
{
    int num = dynamic_cast<Lrational*>(L1)->getNumerator()*dynamic_cast<Lrational*>(L2)->getDenominator();
    int den = dynamic_cast<Lrational*>(L1)->getDenominator()*dynamic_cast<Lrational*>(L2)->getNumerator();
    return (new Lrational(num,den));
}

//Operator DIV
Engine::Expression* Engine::DivintIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()/dynamic_cast<Linteger*>(L2)->getValue()));
}

//Operator MOD
Engine::Expression* Engine::ModIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger((int)dynamic_cast<Linteger*>(L1)->getValue()%(int)dynamic_cast<Linteger*>(L2)->getValue()));
}

//Operator POW
Engine::Expression* Engine::PowIntInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Linteger(pow((int)dynamic_cast<Linteger*>(L1)->getValue(),dynamic_cast<Linteger*>(L2)->getValue())));
}

Engine::Expression* Engine::PowRealInt::executeActionBinary(Expression* L1,Expression* L2)
{
    return (new Lreal(pow(dynamic_cast<Lreal*>(L1)->getValue(),dynamic_cast<Linteger*>(L2)->getValue())));
}

Engine::Expression* Engine::PowRatInt::executeActionBinary(Expression* L1,Expression* L2)
{
    int num = pow(dynamic_cast<Lrational*>(L1)->getNumerator(),dynamic_cast<Linteger*>(L2)->getValue());
    int den = pow(dynamic_cast<Lrational*>(L1)->getDenominator(),dynamic_cast<Linteger*>(L2)->getValue());
    return (new Lrational(num,den));

}
