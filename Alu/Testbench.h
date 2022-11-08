#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
	public:
    	sc_in<bool> clkIn;
		sc_out<sc_bv<32>> rs1Out, rs2Out;
		sc_out<bool> aluOpOut1, aluOpOut2, aluOpOut3;
    	sc_in<sc_bv<32>> resIn;
		sc_in<bool> zeroIn;
    	SC_CTOR(Testbench);

  	private:
   		void print();
    	void test();
};

#endif