#include "expressionmanager.h"

#include "expression.h"
#include "CompException.h"
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

//Engine::ExpressionManager& Engine::ExpressionManager::operator<<(Expression& e){
//    Expression* ex = e.createLitterale();
//    exps.push_back(&e);
//    return *this;
//}

/*
Engine::Expression& Engine::ExpressionManager::addExpression(Expression& e){
    if (nb==nbMax) agrandissementCapacite();
    exps[nb++]= new Expression(e);
    return *exps[nb-1];
}//ajoute une expression au tableau

void Engine::ExpressionManager::removeExpression(Expression& e){
    if (exps != nullptr){
        size_t i = 0;
        while (i<nb && exps[i]!= &e) i++;
        if (i == nb) throw Engine::ComputerException ("Expression Inexistante");
        delete exps[i];
        nb--;
        while(i<nb) exps[i]= exps[i+1]; i++;
    }throw Engine::ComputerException ("Aucune Expression exitante.");
}//supprime une expression du tableau
*/

vector<string> split(const string &cmd, char space)
{
    string buf;
    vector<string> tokens;
    stringstream ss(cmd);
    while (getline(ss, buf, space))
    {
        tokens.push_back(buf);
    }
    return tokens;
}

void Engine::ExpressionManager::evalCommandLine(const string str)
{
    vector<string> tokens = ExpressionManager::split(str, ' '); //on a un les tokens
    for (auto it = std::begin(tokens); it != std::end(tokens); ++it)
    {
        exps.push_back(CreateExpressionFromString(*it));
    }
} //evalue la command line

Engine::Expression *Engine::ExpressionManager::CreateExpressionFromString(const string s)
{
    Expression *res = nullptr;
    for (auto it = expressionsTypes.begin(); it != expressionsTypes.end(); ++it)
    {
        if (it->isSameType(s))
        {
            if (!res)
                res = it->CreateExpressionFromString(s);
            else
                throw ComputerException("Reconnu par plusieurs types");
        }
    }
    if (!res)
        throw ComputerException("Type non reconnu");
    return res;
}

void Engine::ExpressionManager::registerType(const Expression &type)
{
    expressionsTypes.push_back(type);
}

Engine::ExpressionManager::~ExpressionManager()
{
    for (auto e : exps)
    {
        delete e;
    }
}