#ifndef MEM_READ_H 
#define MEM_READ_H

#include <systemc.h>

class MemRead: public sc_module {
public:
    SC_CTOR(MemRead);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    NorGate5 norGate5;

};

#endif