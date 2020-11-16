#include "subject.h"
#include "observer.h"

void Subject::Notify()
{
    std::list<Observer *>::iterator iterator = listObserver.begin();
    while (iterator != listObserver.end()) {
      (*iterator)->Notify("hello");
      ++iterator;
    }
};
void Subject::Attach(Observer* o)
{
    listObserver.push_back(o);
};
void Subject::Detach(Observer* o)
{
    listObserver.remove(o);
};
