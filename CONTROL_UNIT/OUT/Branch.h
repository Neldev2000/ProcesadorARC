#ifndef BRANCH_H
#define BRANCH_H

#include <systemc.h>
#include "And3.h"
#include "Nor.h"

class Branch : public sc_module
{
public:
    SC_CTOR(Branch);
    sc_in<bool> i6, i5, i4, i3;
    sc_out<bool> s;
private:
    /* data */
    AndGate3 andGate3;
    NorGate norGate;
    sc_signal<bool> channels[1];



};

#endif