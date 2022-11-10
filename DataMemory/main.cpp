#include "DataMemory.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
    //@@@@@@@@@Reloj
    sc_time period(10, SC_NS);
    sc_time delay(10, SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    DataMemory datamemory("datamemory");
    Testbench testbench("testbench");

    sc_signal<sc_bv<32>> addressSg, writeDataSg,readDataSg;
    sc_signal<bool>  memWriteSg, memReadSg;

    //@@@@@@@@@Conexion con los Canales correspondientes
	datamemory.address(addressSg);
	datamemory.writeData(writeDataSg);
	datamemory.readData(readDataSg);
	datamemory.memWrite(memWriteSg);
	datamemory.memRead(memReadSg);


	testbench.addressOut(addressSg);
	testbench.writeDataOut(writeDataSg);
	testbench.readDataIn(readDataSg);
	testbench.memWriteOut(memWriteSg);
	testbench.memReadOut(memReadSg);

    testbench.clkIn(clock);

    sc_start();

  return 0;
}