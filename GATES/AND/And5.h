#ifndef AND_5_H
#define AND_5_H
/* code */
#include <systemc.h>

class AndGate5 : public sc_module {
    public:
        SC_CTOR(AndGate5);
        void process();
        sc_in<bool> inA, inB, inC, inD, inE;
        sc_out<bool> output;
};

#endif //AND_H
