#ifndef XOR_3_H
#define XOR_3_H
/* code */
#include <systemc.h>

class XorGate3 : public sc_module {
    public:
        SC_CTOR(XorGate3);
        void process();
        sc_in<bool> inA, inB, inC;
        sc_out<bool> output;
};

#endif //AND_H
