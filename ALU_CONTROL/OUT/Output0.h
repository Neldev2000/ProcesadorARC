#ifndef ALU_OUT_0_H
#define ALU_OUT_0_H

#include <systemc.h>

#include "Nor5.h"
#include "And.h"
#include "Nor4.h"
#include "Nor.h"
#include "And4.h"
#include "Xor.h"
#include "Not.h"
#include "And5.h"
#include "Or5.h"

class Output0: public sc_module {
public:
    SC_CTOR(Output0);

    sc_in<bool> aluOp0, aluOp1, aluOp2;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    NorGate5 norGate5;
    sc_vector<AndGate> andGates;
    NorGate4 norGate4;
    sc_vector<NorGate> norGate;
    AndGate4 andGate4;
    XorGate xorGate;
    NotGate notGate;
    AndGate5 andGate5;
    OrGate5 orGate5;

    sc_signal<bool> channels[11];
};

#endif