#include "subject.h"
#include "observer.h"

void Subject::notify()
{
    std::list<Observer *>::iterator iterator = listObserver.begin();
    while (iterator != listObserver.end()) {
      (*iterator)->notify("hello");
      ++iterator;
    }
};
void Subject::attach(Observer* o)
{
    listObserver.push_back(o);
};
void Subject::detach(Observer* o)
{
    listObserver.remove(o);
};
