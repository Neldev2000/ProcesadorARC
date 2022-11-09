#ifndef ALU_OP_3_H
#define ALU_OP_3_H
/* code */

#include <systemc.h>

#include "And3.h"
#include "Nor3.h"

class AluOp3 : sc_module
{
public:
    SC_CTOR(AluOp3);

    sc_in<bool> i6, i5 i4, i3, i2;
    sc_out<bool> s;

private:
    AndGate3 andGate3;
    NorGate3 norGate3;

    sc_signal<bool> channels[1];

};


#endif //ALU_OP_3_H
