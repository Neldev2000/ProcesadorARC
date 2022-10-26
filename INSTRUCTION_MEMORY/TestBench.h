#ifndef TEST_BENCH_H
#define TEST_BENCH_H
/* code */
#include <systemc.h>
#include <iostream>


class TestBench : public sc_module
{
public:
    SC_CTOR(TestBench);

    sc_in<sc_bv<7>> controlUnit;
    sc_in<sc_bv<5>> rs1, rs2, rd;
    sc_in<sc_bv<32>> immGen;

    sc_out<sc_bv<32>> programCounterIndex; // output
    
    
    sc_in_clk clock;
private:

    

    void printData();
    void test();
};


#endif //TEST_BENCH_H
