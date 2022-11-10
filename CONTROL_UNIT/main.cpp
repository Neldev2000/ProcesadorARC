#include <systemc.h>

#include "ControlUnit.h"
#include "Testbench.h"

#include <vector>
using namespace std;

int sc_main(int argc, char *argv[]) {

    ControlUnit controlUnit("controlUnit");
    Testbench test("testBench");


    sc_signal<bool> regWrite, memWrite, memToReg, memRead, branch, aluSrc, aluOp2, aluOp1, aluOp0;
    sc_signal<bool> i6, i5, i4, i3, i2;

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    controlUnit.i6(i6);
    test.i6(i6);

    controlUnit.i5(i5);
    test.i5(i5);

    controlUnit.i4(i4);
    test.i4(i4);

    controlUnit.i3(i3);
    test.i3(i3);

    controlUnit.i2(i2);
    test.i2(i2);
    
    /////////////////////////////////
    // regWrite, memWrite, memToReg, memRead, branch, aluSrc, aluOp3, aluOp2, aluOp1, aluOp0;

    controlUnit.regWrite(regWrite);
    test.regWrite(regWrite);

    controlUnit.memWrite(memWrite);
    test.memWrite(memWrite);

    controlUnit.memToReg(memToReg);
    test.memToReg(memToReg);

    controlUnit.memRead(memRead);
    test.memRead(memRead);

    controlUnit.branch(branch);
    test.branch(branch);

    controlUnit.aluSrc(aluSrc);
    test.aluSrc(aluSrc);

    controlUnit.aluOp2(aluOp2);
    test.aluOp2(aluOp2);

    controlUnit.aluOp1(aluOp1);
    test.aluOp1(aluOp1);

    controlUnit.aluOp0(aluOp0);
    test.aluOp0(aluOp0);
    test.clock(clock);

    sc_start();
    return 0;
}
