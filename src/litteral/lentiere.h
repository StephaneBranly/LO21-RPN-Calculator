#ifndef LENTIERE_H
#define LENTIERE_H
#include "lnumerique.h"

class lentiere : public lnumerique
{
int valeur;
    
public:

lentiere(int v):valeur(v){}
    int getValue()const;
    ~lentiere();
};

#endif // LENTIERE_H
