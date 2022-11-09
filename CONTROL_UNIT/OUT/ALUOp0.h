#ifndef ALU_OP_0_H
#define ALU_OP_0_H
/* code */

#include <systemc.h>

#include "Nor4.h"
#include "And.h"
#include "Nor.h"
#include "And3.h"
#include "Or.h"

class AluOp0 : sc_module
{
public:
    SC_CTOR(AluOp0);

    sc_in<bool> i6, i5 i4, i3, i2;
    sc_out<bool> s;

private:
    NorGate4 norGate4;
    AndGate andGate;

    NorGate norGate;
    AndGate3 andGate3;

    OrGate orGate;

    sc_signal<bool> channels[4];

};


#endif //ALU_OP_3_H
