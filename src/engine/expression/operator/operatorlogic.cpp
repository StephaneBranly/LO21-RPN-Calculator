#include "operatorlogic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"


Engine::OperatorAnd::OperatorAnd()
{
    registerAction2("Linteger", "Linteger", new AndIntInt);
    registerAction2("Linteger", "Lreal", new AndIntReal);
    registerAction2("Lreal", "Linteger", new AndIntReal);
    registerAction2("Linteger", "Lrational", new AndIntRat);
    registerAction2("Lrational", "Linteger", new AndIntRat);
    registerAction2("Lreal", "Lreal", new AndRealReal);
    registerAction2("Lreal", "Lrational", new AndRealRat);
    registerAction2("Lrational", "Lreal", new AndRealRat);
    registerAction2("Lrational", "Lrational", new AndRatRat);

}
Engine::OperatorOr::OperatorOr()
{
    registerAction2("Linteger", "Linteger", new OrIntInt);
    registerAction2("Linteger", "Lreal", new OrIntReal);
    registerAction2("Lreal", "Linteger", new OrIntReal);
    registerAction2("Linteger", "Lrational", new OrIntRat);
    registerAction2("Lrational", "Linteger", new OrIntRat);
    registerAction2("Lreal", "Lreal", new OrRealReal);
    registerAction2("Lreal", "Lrational", new OrRealRat);
    registerAction2("Lrational", "Lreal", new OrRealRat);
    registerAction2("Lrational", "Lrational", new OrRatRat);

}

/*Engine::OperatorNot::OperatorNot()
{
    registerAction3("Linteger", new NotInt);
    registerAction3("Lreal", new NotReal);
    registerAction3("Lrational", new NotRat);


}*/

Engine::OperatorEq::OperatorEq()
{
    registerAction2("Linteger", "Linteger", new EqIntInt);
    registerAction2("Linteger", "Lreal", new EqIntReal);
    registerAction2("Lreal", "Linteger", new EqIntReal);
    registerAction2("Linteger", "Lrational", new EqIntRat);
    registerAction2("Lrational", "Linteger", new EqIntRat);
    registerAction2("Lreal", "Lreal", new EqRealReal);
    registerAction2("Lreal", "Lrational", new EqRealRat);
    registerAction2("Lrational", "Lreal", new EqRealRat);
    registerAction2("Lrational", "Lrational", new EqRatRat);

}
Engine::OperatorGeq::OperatorGeq()
{
    registerAction2("Linteger", "Linteger", new GeqIntInt);
    registerAction2("Linteger", "Lreal", new GeqIntReal);
    registerAction2("Lreal", "Linteger", new GeqIntReal);
    registerAction2("Linteger", "Lrational", new GeqIntRat);
    registerAction2("Lrational", "Linteger", new GeqIntRat);
    registerAction2("Lreal", "Lreal", new GeqRealReal);
    registerAction2("Lreal", "Lrational", new GeqRealRat);
    registerAction2("Lrational", "Lreal", new GeqRealRat);
    registerAction2("Lrational", "Lrational", new GeqRatRat);

}
Engine::OperatorLeq::OperatorLeq()
{
    registerAction2("Linteger", "Linteger", new LeqIntInt);
    registerAction2("Linteger", "Lreal", new LeqIntReal);
    registerAction2("Lreal", "Linteger", new LeqIntReal);
    registerAction2("Linteger", "Lrational", new LeqIntRat);
    registerAction2("Lrational", "Linteger", new LeqIntRat);
    registerAction2("Lreal", "Lreal", new LeqRealReal);
    registerAction2("Lreal", "Lrational", new LeqRealRat);
    registerAction2("Lrational", "Lreal", new LeqRealRat);
    registerAction2("Lrational", "Lrational", new LeqRatRat);

}
Engine::OperatorGt::OperatorGt()
{
    registerAction2("Linteger", "Linteger", new GtIntInt);
    registerAction2("Linteger", "Lreal", new GtIntReal);
    registerAction2("Lreal", "Linteger", new GtIntReal);
    registerAction2("Linteger", "Lrational", new GtIntRat);
    registerAction2("Lrational", "Linteger", new GtIntRat);
    registerAction2("Lreal", "Lreal", new GtRealReal);
    registerAction2("Lreal", "Lrational", new GtRealRat);
    registerAction2("Lrational", "Lreal", new GtRealRat);
    registerAction2("Lrational", "Lrational", new GtRatRat);

}
Engine::OperatorLt::OperatorLt()
{
    registerAction2("Linteger", "Linteger", new LtIntInt);
    registerAction2("Linteger", "Lreal", new LtIntReal);
    registerAction2("Lreal", "Linteger", new LtIntReal);
    registerAction2("Linteger", "Lrational", new LtIntRat);
    registerAction2("Lrational", "Linteger", new LtIntRat);
    registerAction2("Lreal", "Lreal", new LtRealReal);
    registerAction2("Lreal", "Lrational", new LtRealRat);
    registerAction2("Lrational", "Lreal", new LtRealRat);
    registerAction2("Lrational", "Lrational", new LtRatRat);

}
Engine::OperatorDiff::OperatorDiff()
{
    registerAction2("Linteger", "Linteger", new DiffIntInt);
    registerAction2("Linteger", "Lreal", new DiffIntReal);
    registerAction2("Lreal", "Linteger", new DiffIntReal);
    registerAction2("Linteger", "Lrational", new DiffIntRat);
    registerAction2("Lrational", "Linteger", new DiffIntRat);
    registerAction2("Lreal", "Lreal", new DiffRealReal);
    registerAction2("Lreal", "Lrational", new DiffRealRat);
    registerAction2("Lrational", "Lreal", new DiffRealRat);
    registerAction2("Lrational", "Lrational", new DiffRatRat);

}

void Engine::OperatorLogic::registerAction2(std::string type1, std::string type2, Action2* a)
{
    tuple<string, string> t = make_tuple(type1,type2);
    op.insert(make_pair(t,a));
}


void Engine::OperatorLogic::executeOpe()
{
    Stack& p=ComputerEngine::getInstance().getStack();
    Expression* L1=p.top();
    p.pop();
    Expression* L2=p.top();
    p.pop();

    tuple<string,string> t = make_tuple(L1->getType(),L2->getType());
    if (op.find(t) != op.end())
    {
        p.push(op.at(t)->executeAction(L2,L1));
    }
    else
    {
        throw ComputerException("Action "+toString()+" impossible entre "+L1->getType()+" et "+L2->getType());
    }
}

//OperatorAnd

Engine::Expression* Engine::AndIntInt::executeAction(Expression* L1,Expression* L2)
{
   Linteger* n1=dynamic_cast<Linteger*>(L1);
   Linteger* n2=dynamic_cast<Linteger*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::AndIntRat::executeAction(Expression* L1,Expression* L2)
{

   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::AndIntReal::executeAction(Expression* L1,Expression* L2)
{

   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::AndRatRat::executeAction(Expression* L1,Expression* L2)
{

   Lrational* n1=dynamic_cast<Lrational*>(L1);
   Lrational* n2=dynamic_cast<Lrational*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::AndRealReal::executeAction(Expression* L1,Expression* L2)
{

   Lreal* n1=dynamic_cast<Lreal*>(L1);
   Lreal* n2=dynamic_cast<Lreal*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::AndRealRat::executeAction(Expression* L1,Expression* L2)
{

   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 && n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::OrIntInt::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::OrIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}



Engine::Expression* Engine::OrIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::OrRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::OrRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lrational* n1=dynamic_cast<Lrational*>(L1);
   Lrational* n2=dynamic_cast<Lrational*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::OrRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lreal* n1=dynamic_cast<Lreal*>(L1);
   Lreal* n2=dynamic_cast<Lreal*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {
       if(n1->getValue()!=0 || n2->getValue()!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


/*Engine::Expression* Engine::NotInt::executeAction(Expression* L1)
{
   Linteger* n1=dynamic_cast<Linteger*>(L1);


   if(n1 !=nullptr)
   {
       if(n1->getValue()==0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::NotReal::executeAction(Expression* L1)
{
   Lreal* n1=dynamic_cast<Lreal*>(L1);


   if(n1 !=nullptr)
   {
       if(n1->getValue()==0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::NotRational::executeAction(Expression* L1)
{
   Lrational* n1=dynamic_cast<Lrational*>(L1);


   if(n1 !=nullptr)
   {
       if(n1->getValue()==0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}*/


Engine::Expression* Engine::EqIntInt::executeAction(Expression* L1,Expression* L2)
{
   Linteger* n1=dynamic_cast<Linteger*>(L1);
   Linteger* n2=dynamic_cast<Linteger*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::EqIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::EqIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::EqRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lrational* n1=dynamic_cast<Lrational*>(L1);
   Lrational* n2=dynamic_cast<Lrational*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::EqRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lreal* n1=dynamic_cast<Lreal*>(L1);
   Lreal* n2=dynamic_cast<Lreal*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::EqRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::LtIntInt::executeAction(Expression* L1,Expression* L2)
{
   Linteger* n1=dynamic_cast<Linteger*>(L1);
   Linteger* n2=dynamic_cast<Linteger*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LtIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LtIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LtRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LtRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lrational* n1=dynamic_cast<Lrational*>(L1);
   Lrational* n2=dynamic_cast<Lrational*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LtRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lreal* n1=dynamic_cast<Lreal*>(L1);
   Lreal* n2=dynamic_cast<Lreal*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GtIntInt::executeAction(Expression* L1,Expression* L2)
{
   Linteger* n1=dynamic_cast<Linteger*>(L1);
   Linteger* n2=dynamic_cast<Linteger*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GtIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::GtIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GtRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GtRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lrational* n1=dynamic_cast<Lrational*>(L1);
   Lrational* n2=dynamic_cast<Lrational*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::GtRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lreal* n1=dynamic_cast<Lreal*>(L1);
   Lreal* n2=dynamic_cast<Lreal*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0 && (n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LeqIntInt::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LeqIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LeqIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::LeqRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LeqRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::LeqRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())<0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GeqIntInt::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GeqIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::GeqIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::GeqRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::GeqRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::GeqRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())==0 ||(n1->getValue()- n2->getValue())>0 ){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::DiffIntInt::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}


Engine::Expression* Engine::DiffIntRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::DiffIntReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::DiffRatRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::DiffRealRat::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}

Engine::Expression* Engine::DiffRealReal::executeAction(Expression* L1,Expression* L2)
{
   Lnumerical* n1=dynamic_cast<Lnumerical*>(L1);
   Lnumerical* n2=dynamic_cast<Lnumerical*>(L2);

   if(n1 !=nullptr && n2!=nullptr)
   {

       if((n1->getValue()- n2->getValue())!=0){
           return (new Linteger(1));}
       else
          return (new Linteger(0));
   }
    else throw ComputerException("Erreur, entrez deux nombres");

}
