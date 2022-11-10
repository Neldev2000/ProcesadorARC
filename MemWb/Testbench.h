#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
	public:
    	sc_in<bool> clkIn;

		sc_out<sc_bv<32>> rdOut, rOut;
		sc_out<bool> mtrOut;
		
    	sc_in<sc_bv<32>> rdMuxIn, rMuxIn;
		sc_in<bool> mtrMuxIn;

    	SC_CTOR(Testbench);

  	private:
   		void print();
    	void test();
};

#endif