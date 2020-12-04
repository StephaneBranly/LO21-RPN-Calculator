#include "expressionmanager.h"
#include "expression.h"
#include "../exception/CompException.h"
#include "../computerengine.h"

#include <cstring>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

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
    vector<string> tokens = ExpressionManager::split(str,' '); //on a un les tokens
    for (auto it = std::begin(tokens); it!=std::end(tokens); ++it){
        exps.push_back(CreateExpressionFromString(*it));
    }
}//evalue la command line

Engine::Expression* Engine::ExpressionManager::CreateExpressionFromString(const string s){
    Expression* res = nullptr;
    for(auto it = expressionsTypes.begin(); it!=expressionsTypes.end(); ++it){
        if(it->isSameType(s))
        {
            if(!res)
                res = it->CreateExpressionFromString(s);
            else
                throw ComputerException("Reconnu par plusieurs types");
        }
    }
    if(!res)
        throw ComputerException("Type non reconnu");
    return res;
}

void Engine::ExpressionManager::registerType(const Expression& type)
{
    expressionsTypes.push_back(type);
}

Engine::ExpressionManager::~ExpressionManager(){
    for(auto e : exps) {delete e;}
}


