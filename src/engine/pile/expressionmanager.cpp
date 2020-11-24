#include "expressionmanager.h"

void Engine::ExpressionManager::agrandissementCapacite()
{
    Expression** expsnew = new Expression*[(nbMax+1)*2];
    for (size_t i = 0; i<nb ; i++) expsnew[i]=exps[i];
    nbMax = (nbMax+1)*2;
    Expression** old = exps;
    exps = expsnew;
    delete [] old;
}

void Engine::ExpressionManager::removeExpression(Expression& e){
    //retire une expression du tableau mais ne supprime pas une expression en tant que telle
    size_t i = 0;
    while (i<nb && exps[i]!= &e) i++;
    if (i==nb) throw Engine::CompException("Expression inexistante");
    delete exps[i];
    nb--;
    while (i<nb){exps[i]=exps[i+1]; i++;}
}

Engine::ExpressionManager::~ExpressionManager(){
    for(size_t i = 0; i<nb ; i++) delete exps[i];
    delete[] exps;
}

Engine::ExpressionManager::Handler Engine::ExpressionManager::handler;

Engine::ExpressionManager& Engine::ExpressionManager::getInstance(){
   if(handler.instance==nullptr)
       handler.instance= new ExpressionManager;
   return *handler.instance;
}

void Engine::ExpressionManager::libereinstance(){
    delete handler.instance;
    handler.instance= nullptr;
}
