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

lrationelle& lrationelle::simplifier(){
    int r;
    r=lrationelle::PGCD(numerator,denominator);
    numerator=numerator/r;
    denominator=denominator/r;
    if(denominator<0){
        numerator=-numerator;
        denominator=-denominator;
        }
}

int lrationelle::signe(){

    return ((numerator/denominator)<0?-1:1);

}

void lrationelle::memeDenominateur(lrationelle& F1,lrationelle& F2)
{
   F1.numerator *= F2.denominator;
   F1.denominator *= F2.denominator;
   F2.numerator *= F1.denominator;
   F2.denominator *= F1.denominator;
}


lrationelle& lrationelle::operator=(const lrationelle &F)
{
   numerator=F.numerator;
   denominator=F.denominator;
   return *this;
}


lrationelle& lrationelle::operator-(lrationelle& F1)
{
   lrationelle F=*this;
   memeDenominateur(F1, F);
   F.numerator -=F1.numerator;
   return F.simplifier();
}

lrationelle& lrationelle::operator+(lrationelle& F1)
{
   lrationelle F=*this;
   memeDenominateur(F1, F);
   F.numerator +=F1.numerator;
   return F.simplifier();
}

lrationelle& lrationelle::operator/(const lrationelle &F)
{
   lrationelle F1=F;
   return (*this * F1.inverser()).simplifier();
}


lrationelle& lrationelle::inverser()
{
   lrationelle F = *this;
   F.numerator = denominator;
   F.denominator = numerator;
   return F.simplifier();
}

lrationelle& lrationelle::operator*(const lrationelle &F)
{
   lrationelle F1=*this;
   F1.numerator *= F.numerator;
   F1.denominator *= F.denominator;
   return F1.simplifier();
}


int lrationelle::PGCD(int a, int b){
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
   }





