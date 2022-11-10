#include "MemWb.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
    //@@@@@@@@@Reloj
    sc_time period(10, SC_NS);
    sc_time delay(10, SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    MemWb memwb("memwb");
    Testbench testbench("testbench");

    sc_signal<sc_bv<32>> rdMuxSg, rdSg, rMuxSg, rSg;
    sc_signal<bool>  mtrSg, mtrMuxSg;

    //@@@@@@@@@Conexion con los Canales correspondientes
	memwb.memToReg(mtrSg);
	memwb.memToRegMux(mtrMuxSg);

	memwb.readData(rdSg);
	memwb.readDataMux(rdMuxSg);

	memwb.res(rSg);
	memwb.resMux(rMuxSg);
	

	testbench.mtrOut(mtrSg);
	testbench.mtrMuxIn(mtrMuxSg);

	testbench.rdOut(rdSg);
	testbench.rdMuxIn(rdMuxSg);

	testbench.rOut(rSg);
	testbench.rMuxIn(rMuxSg);

    testbench.clkIn(clock);

    sc_start();

  return 0;
}