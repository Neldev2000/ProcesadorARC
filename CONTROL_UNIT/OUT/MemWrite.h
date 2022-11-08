#ifndef MEM_WRITE_H
#define MEM_WRITE_H

#include <systemc.h>

#include "And.h"
#include "Nor4.h"

class MemWrite : public sc_module
{
private:
    /* data */

    AndGate andGate;
    NorGate4 norGate4;
    sc_signal<bool> channels[1];

public:
    SC_CTOR(MemWrite);
    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;
  
};

#endif