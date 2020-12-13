#ifndef USERVAR_H
#define USERVAR_H

#include "litterales/latom.h"
#include "expression.h"
#include <map>
#include <string>
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
    std::list<std::tuple<std::string,std::string,std::string>> toTupleStringList();
};
}
#endif // USERVAR_H
