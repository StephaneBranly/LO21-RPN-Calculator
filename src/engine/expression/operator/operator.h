#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression.h"
//#include "../../computerengine.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {
    class Operator : public Expression {
        size_t arrity=0;
    public :
//        virtual size_t getArrity() const {return this->arrity;}
        virtual Operator* getCopy() = 0;
    };
}
#endif // OPERATOR_H
