#ifndef EXMEM_H
#define EXMEM_H

#include <systemc.h>
#include <vector>
#include <iostream>


class ExMem: public sc_module {
    public:
        sc_in<sc_bv<32>> sum,res,readData2;
		sc_in<bool> zero,brach,memRead,memWrite,memToReg;
    	sc_out<sc_bv<32>> sumMux,addressDm,rp,writeDataDm;
		sc_out<bool> zeroAnd,brachAnd,memReadDm,memWriteDm,memToRegP;

    	SC_CTOR(ExMem);
	private:
		void operacion();

		
};
#endif 