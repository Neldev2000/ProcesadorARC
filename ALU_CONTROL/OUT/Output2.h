#ifndef ALU_OUT_2_H
#define ALU_OUT_2_H

#include <systemc.h>

#include "And.h"

#include "Or.h"
#include "Or3.h"

#include "Nor.h"
#include "Nor4.h"

#include "Not.h"

class Output2: public sc_module {
public:
    SC_CTOR(Output2);

    sc_in<bool> aluOp0, aluOp1, aluOp2;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    sc_vector<AndGate> andGates; // 5
    sc_vector<NotGate> notGates; // 2
    OrGate orGate;
    OrGate3 orGate3;

    NorGate norGate;
    NorGate4 norGate4;



   sc_signal<bool> channels[10];



};

#endif