#ifndef TEST_H 
#define TEST_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
using namespace std;
class Testbench: public sc_module {
public:
    SC_CTOR(Testbench);
    sc_inout<sc_bv<3>> aluOp;
    sc_inout< sc_bv<32> > instruction;

    sc_inout<sc_bv<3>> aluFunction;


    sc_in_clk clock;

    void test();

private:
    void print();

};

#endif