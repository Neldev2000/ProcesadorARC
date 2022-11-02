#ifndef NOR_H
#define NOR_H
/* code */
#include <systemc.h>

class NorGate : public sc_module {
    public:
        SC_CTOR(NorGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
