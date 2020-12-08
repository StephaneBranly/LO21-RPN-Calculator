#ifndef LATOM_H
#define LATOM_H
#include "../../expression/expression.h"
#include <string>

namespace Engine {
class Latom : public Expression
{
    std::string atom;
protected:
    std::string type="Latom";
public:
    Latom(const std::string s);
    Latom(const Latom&);
    Latom* setLatom(const std::string s);
    std::string getvalue(){return atom;}
    const std::string getType() const override { return this->type; }
    void eval() override;
    std::string const toString() const override{return atom;}
    bool isVarId();
    bool isProgId();
};
}
#endif // LATOM_H
