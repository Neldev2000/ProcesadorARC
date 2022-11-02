#include <systemc.h>

#include "Output1.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[]) {

    Output1 out1("out1");
    Testbench test("testBench");


    sc_signal<bool> channels[8];

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    out1.s(channels[0]);
    test.s(channels[0]);

    out1.aluOp0(channels[1]);
    test.aluOp0(channels[1]);

    out1.aluOp1(channels[2]);
    test.aluOp1(channels[2]);

    out1.aluOp2(channels[3]);
    test.aluOp2(channels[3]);

    out1.i30(channels[4]);
    test.i30(channels[4]);

    out1.i14(channels[5]);
    test.i14(channels[5]);

    out1.i13(channels[6]);
    test.i13(channels[6]);

    out1.i12(channels[7]);
    test.i12(channels[7]);

    test.clock(clock);

    sc_start();
    return 0;
}