#ifndef COMPEXCEPTION_H
#define COMPEXCEPTION_H
#include <string>
#include <exception>

namespace Engine {

class ComputerException : public std::exception {
    std::string info;
public :
    ComputerException(const std::string& str):info(str){}
    const char* what() const noexcept {
           return info.c_str();
        }
};

}

#endif // COMPEXCEPTION_H
