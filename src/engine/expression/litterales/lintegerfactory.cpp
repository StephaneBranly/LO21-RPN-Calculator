#include "lintegerfactory.h"
#include <regex>
#include "linteger.h"

bool Engine::LintegerFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^[0-9]+$");
    return (regex_match(s,str_expr));
}
Engine::Expression* Engine::LintegerFactory::createExpressionFromString(const std::string s)
{
    return new Linteger(s);
}
