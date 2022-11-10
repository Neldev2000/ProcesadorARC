#ifndef TEST_H 
#define TEST_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
using namespace std;
class Testbench: public sc_module {
public:
    SC_CTOR(Testbench);
    sc_out<bool> aluOp0, aluOp1, aluOp2;
    sc_out<bool> i30, i14, i13, i12;

    sc_in<bool> aluF0, aluF1, aluF2;


    sc_in_clk clock;

    void test();

private:
    void print(int i);
    void setData(int i);
    
};

#endif