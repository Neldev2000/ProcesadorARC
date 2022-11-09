#ifndef ALU_OP_2_H
#define ALU_OP_2_H
/* code */

#include <systemc.h>

#include "And5.h"
#include "And.h"
#include "Nor4.h"
#include "Not.h"
#include "Or.h"

class AluOp2 : sc_module
{
public:
    SC_CTOR(AluOp2);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    AndGate5 andGate5;
    AndGate andGate;
    NorGate4 norGate4;
    NotGate notGate;
    OrGate orGate;

    sc_signal<bool> channels[4];

};


#endif //ALU_OP_3_H
