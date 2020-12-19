#include "operatorcond.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lprogram.h"



void::Engine::OperatorIFT::executeOpe(vector<Expression*> e){

    Stack& p = ComputerEngine::getInstance().getStack();
    R1value* a=dynamic_cast<R1value*>(e[1]);
    Lprogram* b=dynamic_cast<Lprogram*>(e[0]);
    if(a->getValue()!=0){
        /*Engine::OperatorEVAL* opE= new Engine::OperatorEVAL();
        opE->Engine::OperatorEVAL::executeOpe(e);*/
        b->eval();
    }
    else if(a->getValue()==0) {

        throw  ComputerException("La valeur du premier argument est 0");
    }


}






