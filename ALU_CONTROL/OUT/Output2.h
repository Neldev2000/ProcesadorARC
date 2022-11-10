#ifndef ALU_OUT_2_H
#define ALU_OUT_2_H

#include <systemc.h>

#include "Nor4.h"
#include "Xor.h"
#include "Xnor.h"

#include "And.h"
#include "Not.h"

#include "Nor5.h"

#include "Nor.h"
#include "Or.h"
#include "And4.h"
#include "Or3.h"

class Output2: public sc_module {
public:
    SC_CTOR(Output2);

    sc_in<bool> aluOp2, aluOp1, aluOp0 ;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    NorGate4 norGate4;
    XorGate xorGates;
    XnorGate xnorGate;
    sc_vector<AndGate> andGates;
    sc_vector<NotGate> notGates;

    NorGate norGate;
    OrGate orGate;
    AndGate4 andGate4;
    OrGate3 orGate3;

    sc_signal<bool> channels[12];



};

#endif