#ifndef TEST_BENCH_H
#define TEST_BENCH_H
/* code */
#include <systemc.h>

class TestBench : public sc_module
{
public:
    SC_CTOR(TestBench);
    sc_out<sc_bv<32>> starter;
    
private:
    void test();
};


#endif //TEST_BENCH_H
