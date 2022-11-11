#ifndef MUX_2_1
#define MUX_2_1

#include <systemc.h>
class Mux2a1 : public sc_module
{
public:
    SC_CTOR(Mux2a1);
    sc_in<bool> controlSignal;
    sc_in<sc_bv<32>> inA, inB;

    sc_out<sc_bv<32>> output;
    
private:
    void process();
};


#endif