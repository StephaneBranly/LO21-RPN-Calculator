#include "expressionmanager.h"
#include "expression.h"
#include "../exception/CompException.h"
#include "../computerengine.h"

#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

#include <QtDebug>

vector<string> Engine::ExpressionManager::split(const string& cmd, char space) {
    string buf;
    vector<string> tokens;
    stringstream ss(cmd);
    while(getline(ss,buf, space)) {
        tokens.push_back(buf);
    }
    return tokens;
}

void Engine::ExpressionManager::evalCommandLine(const string str){
    vector<string> tokens = ExpressionManager::split(str,' ');
    for (auto it = std::begin(tokens); it!=std::end(tokens); ++it){
        qDebug()<<"creation de expression pour :"<<QString::fromStdString(*it);
        try {
            exps.push_back(createExpressionFromString(*it));
        }  catch (ComputerException e) {
            qDebug() << "OUIN OUIN ERREUR:"<<QString::fromStdString(e.getInfo());
        }
//
    }
}

Engine::Expression* Engine::ExpressionManager::createExpressionFromString(const string s){
    Expression* res=nullptr;
    for(auto it = expressionsTypes.begin(); it!=expressionsTypes.end(); ++it){
        if((*it)->isSameType(s))
        {
            if(!res)
            {

                res = (*it)->createExpressionFromString(s);
                qDebug() << "Type reconnu";
            }
            else
                throw ComputerException("Reconnu par plusieurs types");
        }
    }
    if(!res)
        throw ComputerException("Type non reconnu");
    return res;
}

void Engine::ExpressionManager::registerType(Expression* t)
{
    expressionsTypes.push_back(t);
    qDebug() << "\nEnregistrement du type ";/*<< QString::fromStdString(t->getType());*/
}

Engine::ExpressionManager::~ExpressionManager(){
    for(auto e : exps) {delete e;}
}


