#ifndef USERVAR_H
#define USERVAR_H

#include "litterales/lprogram.h"
#include "expression.h"
#include "varmanager.h"

namespace Engine {
class UserVar : public Engine::Expression
{
    Engine::Latom* id;
    UserVar(Engine::Latom* i):id(i){};
    friend class VarManager;
public:
    Engine::Latom* getId() const {return id;}
};
}
#endif // USERVAR_H
