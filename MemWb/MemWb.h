#ifndef MEMWB_H
#define MEMWB_H

#include <systemc.h>
#include <vector>
#include <iostream>


class MemWb: public sc_module {
    public:
        sc_in<sc_bv<32>> readData, res;
		sc_in<bool> memToReg;
    	sc_out<sc_bv<32>> readDataMux, resMux;
		sc_out<bool> memToRegMux;

    	SC_CTOR(MemWb);
	private:
		void operacion();

		
};
#endif 