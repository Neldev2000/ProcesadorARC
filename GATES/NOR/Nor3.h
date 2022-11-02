#ifndef NOR_3_H
#define NOR_3_H
/* code */
#include <systemc.h>

class NorGate3 : public sc_module {
    public:
        SC_CTOR(NorGate3);
        void process();
        sc_in<bool> inA, inB, inC;
        sc_out<bool> output;
};

#endif //AND_H
