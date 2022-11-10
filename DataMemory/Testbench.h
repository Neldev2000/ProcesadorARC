#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
	public:
    	sc_in<bool> clkIn;
		sc_out<sc_bv<32>> addressOut, writeDataOut;
		sc_out<bool> memWriteOut, memReadOut;
    	sc_in<sc_bv<32>> readDataIn;
    	SC_CTOR(Testbench);

  	private:
   		void print();
    	void test();
};

#endif