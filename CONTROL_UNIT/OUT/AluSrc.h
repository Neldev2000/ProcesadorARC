#ifndef ALU_SRC_H
#define ALU_SRC_H
/* code */

#include <systemc.h>

#include "And.h"
#include "And4.h"
#include "Not.h"
#include "Nor3.h"
#include "Nand.h"
#include "Or.h"

class AluSrc : public sc_module
{
public:
    SC_CTOR(AluSrc);
    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;
private:
    sc_vector<AndGate> andGates;
    AndGate4 andGate4;
    NotGate notGate;
    NorGate3 norGate3;
    NandGate nandGate;
    OrGate orGate;

    sc_signal<bool> channels[6];
};


#endif //ALU_SRC_H
