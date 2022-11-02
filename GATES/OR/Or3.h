#ifndef OR_3_H
#define OR_3_H
/* code */
#include <systemc.h>

class OrGate3 : public sc_module {
    public:
        SC_CTOR(OrGate3);
        void process();
        sc_in<bool> inA, inB, inC;
        sc_out<bool> output;
};

#endif //AND_H
