#include "latomfactory.h"
#include "latom.h"
#include <regex>

bool Engine::LatomFactory::isSameType(const std::string s) const
{
    std::regex str_expr1 ("^[A-Z]\\.[0-9]+\\.[A-Z]+");
    std::regex str_expr2 ("^[A-Z]\\.[0-9]*\\.[A-Z]*");
    return (regex_match(s,str_expr1)   ||   regex_match(s,str_expr1));
}
Engine::Latom* Engine::LatomFactory::createExpressionFromString(const std::string s)
{
    return new Latom(s);
}
