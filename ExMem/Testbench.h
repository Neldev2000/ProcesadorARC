#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
	public:
    	sc_in<bool> clkIn;

		sc_out<sc_bv<32>> sumOut,addressOut, resOut,rd2Out;
		sc_out<bool> zOut,bOut, mrOut, mwOut, mtrOut;
		
    	sc_in<sc_bv<32>> sMuxIn, aIn,rpIn, wdIn;
		sc_in<bool> zAndIn,bAndIn, mrDmIn, mwDmIn, mtrPIn;

    	SC_CTOR(Testbench);

  	private:
   		void print();
    	void test();
};

#endif