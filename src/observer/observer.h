#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    ~Observer(){};
    virtual void notify(const std::string &message) = 0;
};

#endif // OBSERVER_H
