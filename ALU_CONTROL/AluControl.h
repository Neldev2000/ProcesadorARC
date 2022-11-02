#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H
/* code */
#include <systemc.h>

#include "Output0.h"
#include "Output1.h"
#include "Output2.h"

#include "And3.h"

class AluControl : public sc_module
{
public:
    SC_CTOR(AluControl);

    void process();

    sc_inout<sc_bv<3>> aluOp;
    sc_inout< sc_bv<32> > instruction;

    sc_inout<sc_bv<3>> aluFunction;
    

private:
  Output0 bitRes0;
  //Output1 bitRes1;
  //Output2 bitRes2;



};


#endif //ALU_CONTROL_H
