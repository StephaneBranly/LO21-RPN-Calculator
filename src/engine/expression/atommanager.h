#ifndef USERVAR_H
#define USERVAR_H

#include "litterales/latom.h"
#include "expression.h"
#include <map>
#include <string>

namespace Engine {
class AtomManager
{
    std::map<std::string, Expression*> atoms;
public:
    bool alreadyExists(const std::string name);
    Expression* getExpressionFromAtom(const Latom* a);
    Expression* getExpressionFromString(const std::string s);
    void removeAtom(const std::string name);
    void addAtom(const std::string name, Expression* expression);
};
}
#endif // USERVAR_H
