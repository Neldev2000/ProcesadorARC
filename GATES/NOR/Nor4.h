#ifndef NOR_4_H
#define NOR_4_H
/* code */
#include <systemc.h>

class NorGate4 : public sc_module {
    public:
        SC_CTOR(NorGate4);
        void process();
        sc_in<bool> inA, inB, inC, inD;
        sc_out<bool> output;
};

#endif //AND_H
