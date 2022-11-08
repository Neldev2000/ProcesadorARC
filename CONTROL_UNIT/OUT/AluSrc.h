#ifndef ALU_SRC_H
#define ALU_SRC_H
/* code */
#include "And.h"
#include "And4.h"
#include "Not.h"
#include "Nor3.h"
#include "Nand.h"
class AluSrc : public sc_module
{
public:
    SC_CTOR(AluSrc);
    sc_in<bool> i6, i5 i4, i3, i2;
    sc_out<bool> s;
private:
    AndGate andGate;
    AndGate4 andGate4;
    NotGate notGate;
    NorGate3 norGate3;
    NandGate nandGate;

    sc_signal<bool> channels[5];
};


#endif //ALU_SRC_H
