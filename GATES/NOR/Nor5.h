#ifndef NOR_5_H
#define NOR_5_H
/* code */
#include <systemc.h>

class NorGate5 : public sc_module {
    public:
        SC_CTOR(NorGate5);
        void process();
        sc_in<bool> inA, inB, inC, inD, inE;
        sc_out<bool> output;
};

#endif //AND_H
