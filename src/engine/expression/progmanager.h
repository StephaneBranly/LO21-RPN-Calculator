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
    std::vector<Latom*> getUserProg (){return programs;};
    bool isProgId(std::string s);
};
}
#endif // PROGMANAGER_H
