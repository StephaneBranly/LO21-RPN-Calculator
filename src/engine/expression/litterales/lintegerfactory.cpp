#include "lintegerfactory.h"
#include <regex>
#include "linteger.h"

// Les Linteger sont une suite d'au moins un chiffre
bool Engine::LintegerFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^[0-9]+$");
    return (regex_match(s,str_expr));
}
Engine::Linteger* Engine::LintegerFactory::createExpressionFromString(const std::string s) const
{
    return new Linteger(s);
}
