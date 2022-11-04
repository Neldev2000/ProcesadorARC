#ifndef ALU_OUT_1_H
#define ALU_OUT_1_H

#include <systemc.h>

#include "And.h"
#include "And4.h"

#include "Or.h"
#include "Not.h"

class Output1: public sc_module {
public:
    SC_CTOR(Output1);

    sc_in<bool> aluOp3, aluOp1;
    sc_in<bool> i30, i14, i13;
    sc_out<bool> s;

private:
    sc_vector<NotGate> notGates;
    AndGate andGate;
    AndGate4 andGate4;
    OrGate orGate;


    sc_signal<bool> channels[4];



};

#endif