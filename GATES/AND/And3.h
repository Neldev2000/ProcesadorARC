#ifndef AND_3_H
#define AND_3_H
/* code */
#include <systemc.h>

class AndGate3 : public sc_module {
    public:
        SC_CTOR(AndGate3);
        void process();
        sc_in<bool> inA, inB, inC;
        sc_out<bool> output;
};

#endif //AND_3_H
