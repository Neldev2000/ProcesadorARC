#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H
/* code */
#include <systemc.h>

class AluControl : public sc_module
{
public:
    SC_CTOR(AluControl);

    void process();

    sc_in<sc_bv<3>> aluOp;
    sc_in< sc_bv<32> > instruction;

    sc_out<sc_bv<3>> aluFunction;


private:
    void buildS0();
    void buildS1();
    void buildS2();

};


#endif //ALU_CONTROL_H
