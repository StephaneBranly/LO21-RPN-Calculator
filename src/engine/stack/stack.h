#ifndef STACK_H
#define STACK_H
#include "../expression/expression.h"
#include <string>
#include <vector>
#include <list>

namespace  Engine {

// Classe pile encapsulant un vector
class Stack {
public :
    Stack() = default;
    ~Stack() = default;
    void push(Expression* item);
    void clear();
    void swap();
    Expression* pop();
    bool isEmpty() const {return items.size()==0; }
    size_t size() const {return items.size();}
    Expression* top () const { return items.back(); }
    std::list<std::string> toStringList();
private:
    std::vector<Expression*> items;
};
}

#endif // STACK_H
