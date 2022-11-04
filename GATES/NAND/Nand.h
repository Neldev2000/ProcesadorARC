#ifndef NAND_H
#define NAND_H
/* code */
#include <systemc.h>

class NandGate : public sc_module {
    public:
        SC_CTOR(NandGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
