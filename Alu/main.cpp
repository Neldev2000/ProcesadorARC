#include "Alu.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
    //@@@@@@@@@Reloj
    sc_time period(10, SC_NS);
    sc_time delay(10, SC_NS);
    sc_clock clock("clock", period, 0.5, delay, true);

    Alu alu("alu");
    Testbench testbench("testbench");

    sc_signal<sc_bv<32>> resSg,rs1Sg,rs2Sg;
    sc_signal<bool>  aluOp1Sg,aluOp2Sg,aluOp3Sg,zeroSg;

    //@@@@@@@@@Conexion con los Canales correspondientes
	alu.rs1(rs1Sg);
	alu.rs2(rs2Sg);
	alu.res(resSg);
	alu.aluOp1(aluOp1Sg);
	alu.aluOp2(aluOp2Sg);
	alu.aluOp3(aluOp3Sg);
	alu.zero(zeroSg);

	testbench.rs1Out(rs1Sg);
	testbench.rs2Out(rs2Sg);
	testbench.resIn(resSg);
	testbench.aluOpOut1(aluOp1Sg);
	testbench.aluOpOut2(aluOp2Sg);
	testbench.aluOpOut3(aluOp3Sg);
	testbench.zeroIn(zeroSg);

    testbench.clkIn(clock);

    sc_start();

  return 0;
}