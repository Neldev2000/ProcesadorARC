#include <systemc.h>

#include "AluControl.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[]) {

    AluControl out2("out2");
    Testbench test("testBench");


    sc_signal<sc_bv<32>> instruction;
    sc_signal<sc_bv<3>> channelALUOp, ALUFunct;

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    out2.aluOp(channelALUOp);
    test.aluOp(channelALUOp);

    out2.instruction(instruction);
    test.instruction(instruction);

    out2.aluFunction(ALUFunct);
    test.aluFunction(ALUFunct);

    

    

    test.clock(clock);

    sc_start();
    return 0;
}