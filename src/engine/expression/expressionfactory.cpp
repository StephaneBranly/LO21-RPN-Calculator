#include "expressionfactory.h"
#include "../exception/CompException.h"
#include <QDebug>

Engine::Expression* Engine::ExpressionAbstractFactory::createExpressionFromString(const std::string s)
{
    Expression* res=nullptr;
    for(auto it = factories.begin(); it!=factories.end(); ++it){
        if((*it)->isSameType(s))
        {
            if(!res)
            {

                res = (*it)->createExpressionFromString(s);
                qDebug() << "Type reconnu : "+QString::fromStdString(res->getType());
            }
            else
                throw ComputerException("Reconnu par plusieurs types");
        }
    }
    if(!res)
        throw ComputerException("Type non reconnu de "+s);
    return res;
}
