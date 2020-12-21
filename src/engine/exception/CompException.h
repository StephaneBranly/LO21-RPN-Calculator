#ifndef COMPEXCEPTION_H
#define COMPEXCEPTION_H
#include <string>
#include <stdexcept>



namespace Engine {

// ComputerException qui herite de std::exception comme la majorite des librairies .cpp (uniformisation)
class ComputerException : public std::exception {
protected:
    std::string info;
public :
    ComputerException(const std::string& str="") noexcept:info(str){}
    const char* what() const noexcept {
           return info.c_str();
        }
    ~ComputerException() noexcept{}
};
}

#endif // COMPEXCEPTION_H
