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

Engine::ExpressionManager::type_literal Engine::ExpressionManager::gettype(const string& str)const{


} //détermine le type d'une expression

vector<string> split(const string& cmd, char space) {
    string buf;
    vector<string> tokens;
    stringstream ss(cmd);
    while(getline(ss,buf, space)) {
        tokens.push_back(buf);
    }
    return tokens;
}

void Engine::ExpressionManager::evalCommandLine(const string str){
    char c[str.size() + 1];
    strcpy(c, str.c_str()); //passage d'un string en char
    //c est un char
    char* pch;
    pch = strtok(c," ");
    while (pch != NULL) {
        //comment faire pour un rationnel ? => 3/4
        pch = strtok (NULL," ");

        /*Pour chaque token pch faire :
         * pch -> string
         * createExpressionFromstring() /!\ pch is a char
         * addExpression (expression)
*/
    }

}//evalue la command line => ce qui est entré par l'utilisateur

Engine::Expression& Engine::ExpressionManager::CreateExpressionFromString (const string s){
    const type_literal type = gettype(s);
    switch (type){
    case Lnumerique :
        //contructeur Lnumerique;
        break;
    case Lexpression :
        //contructeur Lexpression;
        break;
    case Latome :
        //contructeur Latome;
        break;
    case Lprogramme :
        //contructeur Lprogramme;
        break;
    case Lentiere :
        //contructeur Lentiere;
        break;
    case Lreelle :
        //contructeur Lreelle;
        break;
    case Lrationnelle :
        //contructeur Lrationnelle;
        break;
    }

}
