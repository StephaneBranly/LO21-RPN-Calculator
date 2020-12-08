#ifndef USERPROG_H
#define USERPROG_H
#include "litterales/latom.h"
#include "litterales/lprogram.h"
#include "expression.h"
#include "progmanager.h"

namespace Engine {
class UserProg : public Engine::Expression
{
    Engine::Latom* id;
    Engine::Lprogram* programme;
    UserProg(Engine::Latom* i,Engine::Lprogram* p):id(i),programme(p){};
    friend class ProgManager;
public:
    Engine::Latom* getId() const {return id;}
    Engine::Lprogram* getProgramme () const {return programme;}
};
}
#endif // USERPROG_H
