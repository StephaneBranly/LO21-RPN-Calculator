#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer
{
public:
    ~Observer(){};
    void notify(const std::string &message);
};

#endif // OBSERVER_H
