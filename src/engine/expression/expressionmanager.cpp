#include "expressionmanager.h"
#include "expression.h"
#include "../exception/CompException.h"

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
    list<Expression*> commandLineExpressions;
    Expression* current;
    vector<string> tokens = ExpressionManager::split(str,' ');
    for (auto it = std::begin(tokens); it!=std::end(tokens); ++it){
        qDebug()<<"creation de expression pour :"<<QString::fromStdString(*it);
        try {
            current = factory->createExpressionFromString(*it);
            exps.push_back(current);
            commandLineExpressions.push_back(current);
        }  catch (ComputerException e) {
            throw ComputerException("/!\\ EVAL :"+e.getInfo());
        }
//
    }
    for(auto it = commandLineExpressions.begin(); it!=commandLineExpressions.end(); ++it)
    {
        qDebug()<<QString::fromStdString((*it)->toString());
        try{
            (*it)->eval();
        }
        catch (ComputerException e) {
            throw ComputerException("/!\\ EVAL :"+e.getInfo());
        }
    }
}

Engine::ExpressionManager::~ExpressionManager(){
    for(auto e : exps) {delete e;}
}


