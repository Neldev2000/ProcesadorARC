#include <systemc.h>
#include "InstructionMemory.h"
#include "TestBench.h"


int sc_main(int argc, char *argv[]) {
  
    sc_signal< sc_bv<32> > pcChannel, immGenChannel;
    sc_signal<sc_bv<5>> rs1Channel, rs2Channel, rdChannel;
    sc_signal<sc_bv<7>> controlUnitChannel;

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    InstructionMemory instMem("instructionMemory");
    TestBench testBench("testBench");

    instMem.programCounterIndex(pcChannel);
    testBench.programCounterIndex(pcChannel);

    instMem.controlUnit(controlUnitChannel);
    testBench.controlUnit(controlUnitChannel);

    instMem.rs1( rs1Channel );
    testBench.rs1(rs1Channel);

    instMem.rs2(rs2Channel);
    testBench.rs2(rs2Channel);

    instMem.rd( rdChannel );
    testBench.rd( rdChannel );

    instMem.immGen( immGenChannel );
    testBench.immGen(immGenChannel);
    


    testBench.clock(clock);
    sc_start();
    return 0;
}
