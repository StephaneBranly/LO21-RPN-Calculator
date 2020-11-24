#ifndef COMPEXCEPTION_H
#define COMPEXCEPTION_H
#include <string>

namespace Engine {

class CompException{
    std::string info;
public :
    ComputerException(const std::string& str):info(str){}
    std::string getInfo() const {return info;}
};

}

#endif // COMPEXCEPTION_H
