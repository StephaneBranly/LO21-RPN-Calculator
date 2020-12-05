#include "lreelle.h"


void Engine::LReelle::setReel(float r){
    reel = r;
}

Engine::LReelle* Engine::LReelle::createExpressionFromString(const std::string s){
    if (regex_match(s,regex([0-9]*\.[0-9]*););)
       {setLentiere(std::stoi(s,nullptr,10););}
}
