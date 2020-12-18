#include "lexpressionfactory.h"
#include <regex>
#include "lexpression.h"

bool Engine::LexpressionFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^'[A-Z]{1}[0-9A-Z]*'$");
    return (regex_match(s,str_expr));
}
Engine::Lexpression* Engine::LexpressionFactory::createExpressionFromString(const std::string s) const
{
    std::string c = s.substr(1,s.length()-2);
    return new Lexpression(c);
}
