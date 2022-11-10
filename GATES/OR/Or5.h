#ifndef OR_5_H
#define OR_5_H
/* code */
#include <systemc.h>

class OrGate5 : public sc_module {
    public:
        SC_CTOR(OrGate5);
        void process();
        sc_in<bool> inA, inB, inC, inD, inE;
        sc_out<bool> output;
};

#endif //AND_H
