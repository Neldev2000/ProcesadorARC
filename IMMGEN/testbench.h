#ifndef TEST_BENCH_H
#define TEST_BENCH_H
/* code */
#include <systemc.h>
#include <iostream>


class testbench : public sc_module
{
public:
    SC_CTOR(testbench);

    sc_in<sc_bv<32>> intb;
    sc_out<sc_bv<12>> outtb; // output
    sc_in_clk clock;
private:

    void printData();
    void test();
};


#endif //TEST_BENCH_H
