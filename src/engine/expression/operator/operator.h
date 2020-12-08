#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression.h"
//#include "../../computerengine.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {
    class Operator : public Expression {
        static size_t arrity;
    public :
        virtual void eval(){};
        virtual size_t getArrity () const {return this->arrity;}
        virtual Operator* getCopy();
    };
}
#endif // OPERATOR_H
