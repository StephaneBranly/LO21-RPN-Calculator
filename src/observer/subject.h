#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <list>
class Subject
{
public:
    void notify();
    void attach(Observer* o);
    void detach(Observer* o);

private:
    std::list<Observer *> listObserver;
};

#endif // SUBJECT_H
