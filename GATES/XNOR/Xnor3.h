#ifndef XNOR_3_H
#define XNOR_3_H
/* code */
#include <systemc.h>

class XnorGate3 : public sc_module {
    public:
        SC_CTOR(XnorGate3);
        void process();
        sc_in<bool> inA, inB, inC;
        sc_out<bool> output;
};

#endif //AND_H
