#ifndef ALU_OP_2_H
#define ALU_OP_2_H
/* code */

#include <systemc.h>

#include "Nor3.h"
#include "And3.h"
#include "And4.h"
#include "Not.h"
#include "Xnor.h"
#include "Or.h"

class AluOp2 : sc_module
{
public:
    SC_CTOR(AluOp2);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    OrGate orGate;
    NotGate notGate;
    AndGate4 andGate4;

    NorGate3 norGate3;
    AndGate3 andGate3;
    XnorGate xnorGate;

    sc_signal<bool> channels[5];

};


#endif //ALU_OP_3_H
