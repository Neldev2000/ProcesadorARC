#ifndef AND_4_H
#define AND_4_H
/* code */
#include <systemc.h>

class AndGate4 : public sc_module {
    public:
        SC_CTOR(AndGate4);
        void process();
        sc_in<bool> inA, inB, inC, inD;
        sc_out<bool> output;
};

#endif //AND_H
