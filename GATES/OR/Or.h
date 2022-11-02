#ifndef OR_H
#define OR_H
/* code */
#include <systemc.h>

class OrGate : public sc_module {
    public:
        SC_CTOR(OrGate);
        void process();
        sc_in<bool> inA, inB;
        sc_out<bool> output;
};

#endif //AND_H
