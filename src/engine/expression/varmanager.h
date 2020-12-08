#ifndef VARMANAGER_H
#define VARMANAGER_H
#include "litterales/latom.h"


namespace Engine {
class VarManager
{
    std::vector<Latom*> variables;
public:
    std::vector<Latom*> getUserVar () {return variables;}
    bool isVarId(std::string id);
};
}
#endif // VARMANAGER_H
