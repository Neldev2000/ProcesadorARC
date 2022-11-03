#ifndef ALU_OUT_1_H
#define ALU_OUT_1_H

#include <systemc.h>

#include "And.h"
#include "And3.h"

#include "Or4.h"

#include "Nor.h"

#include "Not.h"
#include "Xnor.h"

class Output1: public sc_module {
public:
    SC_CTOR(Output1);

    sc_in<bool> aluOp2, aluOp1, aluOp0;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    sc_vector<NorGate> norGates;
    sc_vector<AndGate> andGates;
    sc_vector<AndGate3> andGates3;
    sc_vector<NotGate> notGates;
    XnorGate xnorGate;
    OrGate4 orGate4;

    sc_signal<bool> channels[9];



};

#endif