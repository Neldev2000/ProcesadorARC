#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H
/* code */
#include <systemc.h>
#include "Output1.h"


class AluControl : public sc_module
{
public:
    SC_CTOR(AluControl);

    void process();

    sc_in<bool> aluOp0,aluOp1, aluOp2 ;
    sc_in< sc_bv<32> > instruction;

    sc_out<bool> aluFunction0, aluFunction1, aluFunction2;


private:
  Output1 mod1;
  Output2 mod2;
  Output3 mod3;

  

};


#endif //ALU_CONTROL_H
