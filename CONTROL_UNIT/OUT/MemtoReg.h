#ifndef MEM_TO_REG_H
#define MEM_TO_REG_H
/* code */

#include <systemc.h>
#include "Nor5.h"
class MemtoReg : sc_module
{
public:
    SC_CTOR(MemtoReg);

    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;

private:
    NorGate5 norGate5;
};


#endif //MEM_TO_REG_H
