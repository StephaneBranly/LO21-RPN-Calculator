#include "operatorlogic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"


Engine::OperatorLogic::~OperatorLogic()
{
    for(auto it = tests.begin(); it!=tests.end(); ++it)
        delete (*it).second;
}

Engine::OperatorLogic::OperatorLogic(const OperatorLogic & o) : Operator(o.getType(),2)
{
    for(auto it = o.tests.begin() ; it!= o.tests.end() ; ++it)
        registerTest(get<0>((*it).first),get<1>((*it).first),(*it).second->getCopy());
};

void Engine::OperatorLogic::registerTest(std::string type1,std::string type2,LogicTest* t)
{
    tuple<string, string> p = make_tuple(type1,type2);
    tests.insert(make_pair(p,t));
}

void Engine::OperatorLogic::executeOpe(vector<Expression*> l)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1=l[0];
    Expression* L2=nullptr;
    std::string tL2="";
    if(getArrity()==2)
    {
        L2=l[1];
        tL2=L2->getType();
    }
    tuple<string,string> t = make_tuple(L1->getType(),tL2);
    if (tests.find(t) != tests.end())
    {
        if(tests.at(t)->test(L1,L2)) p.push(new Linteger(1));
        else p.push(new Linteger(0));
    }
    else
    {
        throw ComputerException("Test "+toString()+" impossible.");
    }
}


Engine::OperatorAnd::OperatorAnd(): OperatorLogic("OperatorAND",2)
{
    registerTest("Linteger","Linteger",new R1testAND);
    registerTest("Linteger","Lreal",new R1testAND);
    registerTest("Linteger","Lrational",new R1testAND);
    registerTest("Lreal","Linteger",new R1testAND);
    registerTest("Lreal","Lreal",new R1testAND);
    registerTest("Lreal","Lrational",new R1testAND);
    registerTest("Lrational","Linteger",new R1testAND);
    registerTest("Lrational","Lreal",new R1testAND);
    registerTest("Lrational","Lrational",new R1testAND);
};

Engine::OperatorOr::OperatorOr(): OperatorLogic("OperatorOR",2)
{
    registerTest("Linteger","Linteger",new R1testOR);
    registerTest("Linteger","Lreal",new R1testOR);
    registerTest("Linteger","Lrational",new R1testOR);
    registerTest("Lreal","Linteger",new R1testOR);
    registerTest("Lreal","Lreal",new R1testOR);
    registerTest("Lreal","Lrational",new R1testOR);
    registerTest("Lrational","Linteger",new R1testOR);
    registerTest("Lrational","Lreal",new R1testOR);
    registerTest("Lrational","Lrational",new R1testOR);
};

Engine::OperatorEq::OperatorEq(): OperatorLogic("OperatorEQ",2)
{
    registerTest("Linteger","Linteger",new R1testEQ);
    registerTest("Linteger","Lreal",new R1testEQ);
    registerTest("Linteger","Lrational",new R1testEQ);
    registerTest("Lreal","Linteger",new R1testEQ);
    registerTest("Lreal","Lreal",new R1testEQ);
    registerTest("Lreal","Lrational",new R1testEQ);
    registerTest("Lrational","Linteger",new R1testEQ);
    registerTest("Lrational","Lreal",new R1testEQ);
    registerTest("Lrational","Lrational",new R1testEQ);
};

Engine::OperatorNot::OperatorNot(): OperatorLogic("OperatorNOT",1)
{
    registerTest("Linteger","",new R1testNOT);
    registerTest("Lreal","",new R1testNOT);
    registerTest("Lrational","",new R1testNOT);
};
Engine::OperatorNot::OperatorNot(const OperatorNot & o): OperatorLogic("OperatorNOT",1)
{
    for(auto it = o.tests.begin() ; it!= o.tests.end() ; ++it)
        registerTest(get<0>((*it).first),get<1>((*it).first),(*it).second->getCopy());
};
Engine::OperatorGeq::OperatorGeq(): OperatorLogic("OperatorGEQ",2)
{
    registerTest("Linteger","Linteger",new R1testGEQ);
    registerTest("Linteger","Lreal",new R1testEQ);
    registerTest("Linteger","Lrational",new R1testGEQ);
    registerTest("Lreal","Linteger",new R1testGEQ);
    registerTest("Lreal","Lreal",new R1testGEQ);
    registerTest("Lreal","Lrational",new R1testGEQ);
    registerTest("Lrational","Linteger",new R1testGEQ);
    registerTest("Lrational","Lreal",new R1testGEQ);
    registerTest("Lrational","Lrational",new R1testGEQ);
};

Engine::OperatorLeq::OperatorLeq(): OperatorLogic("OperatorLEQ",2)
{
    registerTest("Linteger","Linteger",new R1testLEQ);
    registerTest("Linteger","Lreal",new R1testLEQ);
    registerTest("Linteger","Lrational",new R1testLEQ);
    registerTest("Lreal","Linteger",new R1testLEQ);
    registerTest("Lreal","Lreal",new R1testLEQ);
    registerTest("Lreal","Lrational",new R1testLEQ);
    registerTest("Lrational","Linteger",new R1testLEQ);
    registerTest("Lrational","Lreal",new R1testLEQ);
    registerTest("Lrational","Lrational",new R1testLEQ);
};
Engine::OperatorDiff::OperatorDiff(): OperatorLogic("OperatorDIFF",2)
{
    registerTest("Linteger","Linteger",new R1testDIFF);
    registerTest("Linteger","Lreal",new R1testDIFF);
    registerTest("Linteger","Lrational",new R1testDIFF);
    registerTest("Lreal","Linteger",new R1testDIFF);
    registerTest("Lreal","Lreal",new R1testDIFF);
    registerTest("Lreal","Lrational",new R1testDIFF);
    registerTest("Lrational","Linteger",new R1testDIFF);
    registerTest("Lrational","Lreal",new R1testDIFF);
    registerTest("Lrational","Lrational",new R1testDIFF);
};

Engine::OperatorLt::OperatorLt(): OperatorLogic("OperatorLT",2)
{
    registerTest("Linteger","Linteger",new R1testLT);
    registerTest("Linteger","Lreal",new R1testLT);
    registerTest("Linteger","Lrational",new R1testLT);
    registerTest("Lreal","Linteger",new R1testLT);
    registerTest("Lreal","Lreal",new R1testLT);
    registerTest("Lreal","Lrational",new R1testLT);
    registerTest("Lrational","Linteger",new R1testLT);
    registerTest("Lrational","Lreal",new R1testLT);
    registerTest("Lrational","Lrational",new R1testLT);
};

Engine::OperatorGt::OperatorGt(): OperatorLogic("OperatorGT",2)
{
    registerTest("Linteger","Linteger",new R1testGT);
    registerTest("Linteger","Lreal",new R1testGT);
    registerTest("Linteger","Lrational",new R1testGT);
    registerTest("Lreal","Linteger",new R1testGT);
    registerTest("Lreal","Lreal",new R1testGT);
    registerTest("Lreal","Lrational",new R1testGT);
    registerTest("Lrational","Linteger",new R1testGT);
    registerTest("Lrational","Lreal",new R1testGT);
    registerTest("Lrational","Lrational",new R1testGT);
};
