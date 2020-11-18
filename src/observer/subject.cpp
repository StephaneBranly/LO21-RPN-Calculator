#include "subject.h"
#include "observer.h"

#include <string>
#include <QtDebug>

void Subject::notify(const std::string& message)
{
    std::list<Observer *>::iterator iterator = listObserver.begin();
    while (iterator != listObserver.end()) {
      (*iterator)->notify(message);
      ++iterator;
    }
};
void Subject::attach(Observer* obs)
{
    listObserver.push_back(obs);
};
void Subject::detach(Observer* obs)
{
    listObserver.remove(obs);
};
