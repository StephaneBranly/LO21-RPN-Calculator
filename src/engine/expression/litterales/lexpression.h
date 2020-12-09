#ifndef LEXPRESSION_H
#define LEXPRESSION_H

#include "../../expression/expression.h"
#include <string>

namespace Engine {
class Lexpression: public Expression
{
    std::string expression;
protected:
    std::string type="Lexpression";
public:
    Lexpression(const std::string s): expression(s){};
//    Lexpression(const Lexpression&);
    Lexpression* setLatom(const std::string s);
    std::string getValue(){return expression;}
    const std::string getType() const override { return this->type; }
    void eval() override;
    std::string const toString() const override{return "'"+expression+"'";}
};
}
#endif // LEXPRESSION_H
