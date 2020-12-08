#ifndef PROGMANAGER_H
#define PROGMANAGER_H
#include <vector>
#include "userprog.h"
#include <string>

namespace Engine {
class ProgManager
{
    std::vector<Latom*> programs;

public:
    ProgManager();
    Latom* getUserProg (std::string id);
};
}
#endif // PROGMANAGER_H
