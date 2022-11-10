#include "ExMem.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
    //@@@@@@@@@Reloj
    sc_time period(10, SC_NS);
    sc_time delay(10, SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    ExMem exmem ("exmem");
    Testbench testbench("testbench");

    sc_signal<sc_bv<32>> rdSg,resSg,sSg,sMuxSg,aSg,wdSg;
    sc_signal<bool>  zSg,zAndSg,bAndSg,mrDmSg,mwDmSg,mtrDmSg,mtrPSg,mtrSg,mwSg,mrSg,bSg;

    //@@@@@@@@@Conexion con los Canales correspondientes
	exmem.sum(sSg);
	exmem.sumMux(sMuxSg);

	exmem.zero(zSg);
	exmem.zeroAnd(zAndSg);

	exmem.res(resSg);
	exmem.addressDm(aSg);

	exmem.readData2(rdSg);
	exmem.writeDataDm(wdSg);

	exmem.brach(bSg);
	exmem.brachAnd(bAndSg);

	exmem.memRead(mrSg);
	exmem.memReadDm(mrDmSg);

	exmem.memWrite(mwSg);
	exmem.memWriteDm(mwDmSg);

	exmem.memToReg(mtrSg);
	exmem.memToRegP(mtrPSg);
	

	testbench.sumOut(sSg);
	testbench.sMuxIn(sMuxSg);

	testbench.zOut(zSg);
	testbench.zAndIn(zAndSg);

	testbench.resOut(resSg);
	testbench.aIn(aSg);

	testbench.rd2Out(rdSg);
	testbench.wdIn(wdSg);

	testbench.bOut(bSg);
	testbench.bAndIn(bAndSg);

	testbench.mrOut(mrSg);
	testbench.mrDmIn(mrDmSg);

	testbench.mwOut(mwSg);
	testbench.mwDmIn(mwDmSg);

	testbench.mtrOut(mtrSg);
	testbench.mtrPIn(mtrPSg);	

    testbench.clkIn(clock);

    sc_start();

  return 0;
}