#ifndef ALU_OUT_0_H
#define ALU_OUT_0_H

#include <systemc.h>

#include "And.h"
#include "And3.h"

#include "Or.h"

#include "Nand.h"
#include "Nor3.h"

#include "Not.h"

class Output0: public sc_module {
public:
    SC_CTOR(Output0);

    sc_in<bool> aluOp3, aluOp2, aluOp1, aluOp0;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    sc_vector<NotGate> notGates;
    sc_vector<AndGate3> andGates3;
    sc_vector<AndGate> andGates;
    sc_vector<OrGate> orGates;


    NandGate nandGate;
    NorGate3 norGate3;

    sc_signal<bool> channels[11];



};

#endif