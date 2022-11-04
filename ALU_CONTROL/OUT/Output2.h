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

    sc_in<bool> aluOp3, aluOp2 ;
    sc_in<bool> i30, i14, i13, i12;
    sc_out<bool> s;

private:
    sc_vector<AndGate> andGates; // 3
    sc_vector<NotGate> notGates; // 2
    sc_vector<OrGate> orGates;   // 2

    AndGate3 andGate3;
    XnorGate xnorGate;
    NorGate norGate;



   sc_signal<bool> channels[];



};

#endif