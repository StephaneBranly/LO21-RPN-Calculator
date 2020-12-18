#include "expressionmanager.h"
#include "expression.h"
#include "../exception/CompException.h"
#include "litterales/lprogram.h"

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
    list<Expression*> commandLineExpressions;
    list<Lprogram*> prof;
    Expression* current;
    vector<string> tokens = ExpressionManager::split(str,' ');

    for (auto it = std::begin(tokens); it!=std::end(tokens); ++it){
        if(*it!=" "&&*it!="")
        {
            if(*it=="[")
            {
                current = new Lprogram;
                if(prof.empty())
                    commandLineExpressions.push_back(current);
                else
                    prof.back()->push_back(current);
                prof.push_back(dynamic_cast<Lprogram*>(current));
            }else if(*it=="]")
            {
                if(prof.empty())
                    throw ComputerException("Crochet ] en trop...");
                else
                    prof.pop_back();
            } else
            {
                try {
                    current = factory->createExpressionFromString(*it);
                    if(prof.empty())
                    {
                        commandLineExpressions.push_back(current);
                        exps.push_back(current);
                    }
                    else
                        prof.back()->push_back(current);

                }  catch (ComputerException e) {
                    throw ComputerException(e.what());
                }
            }
        }
    }
    if(!prof.empty())
        throw ComputerException("Crochet ] manquant...");

    for(auto it = commandLineExpressions.begin(); it!=commandLineExpressions.end(); ++it)
    {
        try{      
            (*it)->eval();
        }
        catch (ComputerException e) {
            contentEval = "";
            for(auto itC = it; itC!=commandLineExpressions.end(); ++itC)
            {
                contentEval += (*itC)->toString()+" ";
                delete (*itC);
            }
            ComputerEngine::getInstance().notify("updateCommandLine");
            throw ComputerException(e.what());
        }
    }
}

Engine::ExpressionManager::~ExpressionManager(){
//    for(auto e : exps) {delete e;}
}


