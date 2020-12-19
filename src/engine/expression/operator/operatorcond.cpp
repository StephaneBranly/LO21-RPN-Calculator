#include "operatorcond.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lprogram.h"



void::Engine::OperatorIFT::executeOpe(vector<Expression*> e){

    Stack& p = ComputerEngine::getInstance().getStack();
    R1value* a=dynamic_cast<R1value*>(e[1]);

    if(a->getValue()!=0){
        Engine::OperatorEVAL* opE= new Engine::OperatorEVAL();
        opE->Engine::OperatorEVAL::executeOpe(e);

    }
    else if(a->getValue()==0) {

        throw  ComputerException("Le resultat du test est faux");
    }


}

void::Engine::OperatorIFTE::executeOpe(vector<Expression*> e){

    Stack& p = ComputerEngine::getInstance().getStack();
    R1value* a=dynamic_cast<R1value*>(e[2]);

    if(a->getValue()!=0){
        Engine::OperatorIFT* opI= new Engine::OperatorIFT();
        opI->Engine::OperatorIFT::executeOpe(e);

    }
    else if(a->getValue()==0) {

        throw  ComputerException("Le resultat du test est faux");

    }


}






