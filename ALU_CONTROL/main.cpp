#include <systemc.h>

#include "AluControl.h"
#include "Testbench.h"

#include <vector>
using namespace std;

int sc_main(int argc, char *argv[]) {

    AluControl out2("out2");
    Testbench test("testBench");


    sc_signal<bool> channelALUOp0, channelALUOp1, channelALUOp2, aluF0, aluF1, aluF2;
    sc_signal<bool> i30, i14, i13, i12;

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    out2.aluOp0(channelALUOp0);
    test.aluOp0(channelALUOp0);

    out2.aluOp1(channelALUOp1);
    test.aluOp1(channelALUOp1);

    out2.aluOp2(channelALUOp2);
    test.aluOp2(channelALUOp2);

    out2.i30(i30);
    test.i30(i30);

    out2.i14(i14);
    test.i14(i14);

    out2.i13(i13);
    test.i13(i13);

    out2.i12(i12);
    test.i12(i12);

    out2.aluF0(aluF0);
    test.aluF0(aluF0);

    out2.aluF1(aluF1);
    test.aluF1(aluF1);

    out2.aluF2(aluF2);
    test.aluF2(aluF2);

    test.clock(clock);

    sc_start();
    return 0;
}