#ifndef AND_H
#define AND_H
/* code */
#include <systemc.h>

class AndGate : public sc_module {
    public:
        SC_CTOR(AndGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
