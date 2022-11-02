#ifndef NOT_H
#define NOT_H
/* code */
#include <systemc.h>

class NotGate : public sc_module {
    public:
        SC_CTOR(NotGate);
        void process();
        sc_in<bool> inA;
        sc_out<bool> output;
};

#endif //AND_H
