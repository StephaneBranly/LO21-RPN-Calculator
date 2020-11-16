#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <list>
#include <string>

class Subject
{
public:
    void notify(const std::string& message);
    void attach(Observer* obs);
    void detach(Observer* obs);

private:
    std::list<Observer *> listObserver;
};

#endif // SUBJECT_H
