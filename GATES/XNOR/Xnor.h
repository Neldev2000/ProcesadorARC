#ifndef XNOR_H
#define XNOR_H
/* code */
#include <systemc.h>

class XnorGate : public sc_module {
    public:
        SC_CTOR(XnorGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
