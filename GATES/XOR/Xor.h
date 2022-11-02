#ifndef XOR_H
#define XOR_H
/* code */
#include <systemc.h>

class XorGate : public sc_module {
    public:
        SC_CTOR(XorGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
