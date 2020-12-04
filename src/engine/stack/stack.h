#ifndef PILE_H
#define PILE_H
#include "../expression/expression.h"
#include <string>
#include <vector>

namespace  Engine {

class Stack {

public :
    Stack() = default;
    ~Stack() {}
    void push(Expression* item){ items.push_back(item); }
    Expression* pop();
    bool isEmpty() const {return items.size()==0; }
    size_t size() const {return items.size();}
    Expression* top () const { return items.back(); }

private:
    std::vector<Expression*> items;
    std::string message="";
    void agrandissementCapacite();
};
}

#endif // PILE_H
