#include "latomfactory.h"
#include "latom.h"
#include <regex>

bool Engine::LatomFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^[A-Z][0-9A-Z]*$");
    return (regex_match(s,str_expr));
}
Engine::Latom* Engine::LatomFactory::createExpressionFromString(const std::string s)
{
    return new Latom(s);
}
