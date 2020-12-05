#ifndef LNUMERIQUE_H
#define LNUMERIQUE_H
#include "litteral.h"


template<class A>
class lnumerique:public litteral
{
public:
   virtual A getValue();
    
};

#endif // LNUMERIQUE_H
