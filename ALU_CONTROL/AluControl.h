#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H
/* code */
#include <systemc.h>

#include "Output0.h"
#include "Output1.h"
#include "Output2.h"

class AluControl : public sc_module
{
public:
    SC_CTOR(AluControl);

   // void process();

    sc_in<bool> aluOp0, aluOp1, aluOp2;
    sc_in<bool> i30, i14, i13, i12;

    sc_out<bool> aluF0, aluF1, aluF2;
    

private:
  Output0 bitRes0;
  Output1 bitRes1;
  Output2 bitRes2;


};


#endif //ALU_CONTROL_H
