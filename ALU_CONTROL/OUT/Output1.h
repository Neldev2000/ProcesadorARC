#ifndef ALU_OUT_1_H
#define ALU_OUT_1_H

#include <systemc.h>

#include "And5.h"
#include "And3.h"
#include "Not.h"
#include "Nor.h"
#include "Or.h"
#include "And.h"
#include "Or3.h"

class Output1: public sc_module {
public:
    SC_CTOR(Output1);

    sc_in<bool> aluOp2, aluOp1, aluOp0;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    AndGate5 andGate5;

    sc_vector<AndGate3> andGates3;
    sc_vector<NotGate> notGates;
    sc_vector<NorGate> norGates;
    OrGate orGate;
    AndGate andGate;
    OrGate3 orGate3;

    sc_signal<bool> channels[11];



};

#endif