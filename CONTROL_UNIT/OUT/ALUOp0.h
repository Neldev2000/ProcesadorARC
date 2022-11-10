#ifndef ALU_OP_0_H
#define ALU_OP_0_H
/* code */

#include <systemc.h>

#include "Nor5.h"
#include "And4.h"
#include "Not.h"
#include "Or.h"

class AluOp0 : sc_module
{
public:
    SC_CTOR(AluOp0);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    NorGate5 norGate5;
    AndGate4 andGate4;
    NotGate notGate;
    OrGate orGate; 

    sc_signal<bool> channels[3];

};


#endif //ALU_OP_3_H
