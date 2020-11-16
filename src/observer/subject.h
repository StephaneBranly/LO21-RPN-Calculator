#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <list>
class Subject
{
public:
    virtual void Notify() = 0;
    virtual void Attach(Observer* o) = 0;
    virtual void Detach(Observer* o) = 0;

private:
    std::list<Observer *> listObserver;
};

#endif // SUBJECT_H
