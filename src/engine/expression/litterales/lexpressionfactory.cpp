#include "lexpressionfactory.h"
#include <regex>
#include "lexpression.h"

// Les Lexpression commencent par ' suivi d'une lettre majuscule et suivi de un ou plusieurs chiffres et lettres, se termine par '
bool Engine::LexpressionFactory::isSameType(const std::string s) const
{
    std::regex str_expr ("^'[A-Z]{1}[0-9A-Z]*'$");
    return (regex_match(s,str_expr));
}
Engine::Lexpression* Engine::LexpressionFactory::createExpressionFromString(const std::string s) const
{
    std::string c = s.substr(1,s.length()-2); // on retire les '' pour enregistrer le contenu de l'expression
    return new Lexpression(c);
}
