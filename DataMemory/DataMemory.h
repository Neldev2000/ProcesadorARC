#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <systemc.h>
#include <vector>
#include <iostream>
#include <fstream>


class DataMemory: public sc_module {
    public:
        sc_in<sc_bv<32>> address, writeData;
		sc_in<bool> memWrite, memRead;
    	sc_out<sc_bv<32>> readData;

    	SC_CTOR(DataMemory);
	private:
		void operacion();
		std::vector <sc_bv<32>> data;
		std::fstream archivo;
  		
		void escribir();
		void leer();

		
};
#endif 