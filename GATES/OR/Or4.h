#ifndef OR_4_H
#define OR_4_H
/* code */
#include <systemc.h>

class OrGate4 : public sc_module {
    public:
        SC_CTOR(OrGate4);
        void process();
        sc_in<bool> inA, inB, inC, inD;
        sc_out<bool> output;
};

#endif //AND_H
