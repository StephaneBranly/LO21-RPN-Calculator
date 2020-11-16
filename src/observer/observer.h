#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    virtual ~Observer(){};
    virtual void Notify(const std::string &message) = 0;
};

#endif // OBSERVER_H
