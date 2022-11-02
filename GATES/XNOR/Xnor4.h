#ifndef XNOR_4_H
#define XNOR_4_H
/* code */
#include <systemc.h>

class XnorGate4 : public sc_module {
    public:
        SC_CTOR(XnorGate4);
        void process();
        sc_in<bool> inA, inB, inC, inD;
        sc_out<bool> output;
};

#endif //AND_H
