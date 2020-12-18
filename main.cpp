#include "src/interface/mainwindow.h"
#include "src/engine/computerengine.h"
#include "src/connector/connector.h"

#include "src/engine/expression/operator/operatoraritbinary.h"
#include "src/engine/expression/litterales/lexpression.h"

#include <QApplication>

#include <iostream>

//namespace Engine {
//    class ActionConc : public Engine::ActionBinary
//    {
//        Expression* executeActionBinary(Expression* L1,Expression* L2) override
//        {
//            Lexpression* exp = dynamic_cast<Lexpression*>(L1);
//            return new Lexpression(exp->getValue()+L2->toString());
//        };
//        ActionBinary* getCopy() const override { return new ActionConc; }
//    };
//}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Mainwindow& w = *(new Mainwindow);
    Engine::ComputerEngine e = Engine::ComputerEngine::getInstance();
    Connector c(w,e);


//    Engine::Expression* exp = e.getInstance().getExpressionManager().getFactory()->getOperatorFactory()->getOriginalOperatorFromString("+");
//    Engine::OperatorAritBinary* op = dynamic_cast<Engine::OperatorAritBinary*>(exp);
//    op->registerActionBinary("Linteger","Lexpression",new Engine::ActionConc);
    return a.exec();
}
