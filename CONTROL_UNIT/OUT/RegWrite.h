#ifndef REG_WRITE_H
#define REG_WRITE_H
 /* code */
#include <systemc.h>

#include "And.h"
#include "Nor3.h"
#include "And4.h"
#include "Not.h"
#include "Or.h"

class RegWrite : public sc_module
{
public:
    SC_CTOR(RegWrite);
    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> s;
private:
    sc_vector<AndGate> andGates;
    NorGate3 norGate3;
    AndGate4 andGate4;
    sc_vector<NotGate> notGates;
    sc_vector<OrGate> orGates;
    sc_signal<bool> channels[7];
};

#endif //REG_WRITE_H
