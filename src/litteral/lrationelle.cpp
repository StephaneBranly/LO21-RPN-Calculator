#include "lrationelle.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int lrationelle::getNumerator() const{

    return numerator;
}

void lrationelle::setNumerator(int n){
    numerator=n;
}

int lrationelle::getDenominator() const{
    return denominator;
}

void lrationelle::setDenominator(int d){
    if(d==0)
       throw runtime_error("Denominateur nul");
    else
       denominator=d;

}
