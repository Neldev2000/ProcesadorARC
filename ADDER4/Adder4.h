#ifndef ADDER_4_H
#define ADDER_4_H
/* code */
#include <systemc.h>
class Adder4 : public sc_module
{
public:
    SC_CTOR(Adder4);
    
    sc_in< sc_bv<32>> pcIn;
    sc_out<sc_bv<32>> pcOut;

private:
    void process();
};


#endif //ADDER_4_H
