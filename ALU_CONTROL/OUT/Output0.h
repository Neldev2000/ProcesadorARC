#ifndef ALU_OUT_0_H
#define ALU_OUT_0_H

#include <systemc.h>

#include "And.h"
#include "And3.h"

#include "Or.h"
#include "Or3.h"

#include "Nor.h"
#include "Nor4.h"

#include "Not.h"
#include "Xor.h"

class Output0: public sc_module {
public:
    SC_CTOR(Output0);

    sc_inout<bool> aluOp0, aluOp1, aluOp2;
    sc_inout<bool> i30, i14, i13, i12;
    sc_inout<bool> s;

private:
    sc_vector<AndGate> andGates;
    sc_vector<AndGate3> andGates3;
    
    OrGate orGate;
    OrGate3 orGate3;

    NorGate4 norGate4;
    NorGate norGate;

    NotGate notGate;
    XorGate xorGate;

    sc_signal<bool> channels[9];



};

#endif