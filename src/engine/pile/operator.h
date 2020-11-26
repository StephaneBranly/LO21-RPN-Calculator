#ifndef OPERATOR_H
#define OPERATOR_H


namespace Engine {
    class Operator {

    };

    class Operatorplus : public Operator {
        int arrite=2;
    public :
        Operatorplus () {}
        eval()
        {
           if (getSize() < arrite)
               throw ComputerException ("La pile ne contient pas assez de valeurs à additioner");
           auto L1 = pop();
           auto L2 = pop();
           try {

           } catch (...) {
           }

        }

    };
}
#endif // OPERATOR_H
