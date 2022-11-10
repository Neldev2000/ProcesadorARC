#ifndef ALU_OP_1_H
#define ALU_OP_1_H
/* code */

#include <systemc.h>

#include "Xnor.h"
#include "Nor.h"
#include "And3.h"
#include "Nor3.h"
#include "Or.h"

class AluOp1 : sc_module
{
public:
    SC_CTOR(AluOp1);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    XnorGate xnorGate;
    NorGate norGate;
    sc_vector<AndGate3> andGates3;
    NorGate3 norGate3;
    OrGate orGate;

    sc_signal<bool> channels[5];

};


#endif //ALU_OP_3_H
