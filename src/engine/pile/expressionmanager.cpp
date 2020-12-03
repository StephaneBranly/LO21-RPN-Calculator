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
#include <regex>



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

std::string Engine::ExpressionManager::gettype(const string& str)const{
    if (regex_match (str, regex("^[0-9]+$"))) {return "entier";}
    //int, reelle, operateur + - * /
    if (regex_match) {return "reel";}
    if (regex_match){return "operateur+";}
    if (regex_match){return "operateur-";}
    if (regex_match){return "operateur/";}
    if (regex_match){return "operateur*";}
} //détermine le type d'une expression

vector<string> split(const string& cmd, char space) {
    string buf;
    vector<string> tokens;
    stringstream ss(cmd);
    while(getline(ss,buf, space)) {
        tokens.push_back(buf);
    }
    return tokens;
}//ajouter le cas ou on a un / ... (penser à tous les cas)

void Engine::ExpressionManager::evalCommandLine(const string str){
    vector<string> tokens = ExpressionManager::split(str,' '); //on a un les tokens
    for (auto it = std::begin(tokens); it!=std::end(tokens); ++it){
        addExpression(CreateExpressionFromString(*it));
    }
}//evalue la command line

Engine::Expression& Engine::ExpressionManager::CreateExpressionFromString (const string s){
    const std::string type = gettype(s);
    if (type == "entier"){
        //return new Lentier::Lentier(const_cast<integer>(str));
    }else if (type == "reel"){
        //return new Lreelle::Lreelle(const_cast<float>(str));

    }else if (type == "operateur+") {
        //return new Operateurplus::operateurplus(str);
    }else if (type == "operateur-"){
        //return new Operateurmoins::operateurmoins(str);
    }else if (type == "operateur/") {
        //return new Operateurdiv::operateurdiv(str);
    }else if (type == "operateur*") {
        //return new Operateurmult::operateurmult(str);
    }else throw ComputerException("Erreur : Pas de type");

}
