#ifndef LRATIONELLE_H
#define LRATIONELLE_H
#include "lnumerique.h"


class lrationelle : public lnumerique
{
int numerator;
int denominator;

public:
   int getNumerator() const;
   void setNumerator(int n) ;
   int getDenominator() const;
   void setDenominator(int d);
};

#endif // LRATIONELLE_H
