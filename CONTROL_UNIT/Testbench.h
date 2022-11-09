#ifndef TEST_H 
#define TEST_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
using namespace std;
class Testbench: public sc_module {
public:
    SC_CTOR(Testbench);
    sc_in<bool> regWrite, memWrite, memToReg, memRead, branch, aluSrc, aluOp3, aluOp2, aluOp1, aluOp0;
    sc_out<bool> i6, i5, i4, i3, i2;


    sc_in_clk clock;

    void test();

private:
    void print(int i);
    void setData(int i);
    
};

#endif