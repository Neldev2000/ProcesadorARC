#ifndef XOR_4_H
#define XOR_4_H
/* code */
#include <systemc.h>

class XorGate4 : public sc_module {
    public:
        SC_CTOR(XorGate4);
        void process();
        sc_in<bool> inA, inB, inC, inD;
        sc_out<bool> output;
};

#endif //AND_H
