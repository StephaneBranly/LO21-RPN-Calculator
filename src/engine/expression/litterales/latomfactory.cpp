#include "latomfactory.h"
#include "latom.h"
#include <regex>

// Les Latom commencent par une Lettre Majuscule puis peuvent etre suivis de un ou plusieurs Lettres et Chiffres
bool Engine::LatomFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^[A-Z][0-9A-Z]*$");
    return (regex_match(s,str_expr));
}
Engine::Latom* Engine::LatomFactory::createExpressionFromString(const std::string s) const
{
    return new Latom(s);
}
