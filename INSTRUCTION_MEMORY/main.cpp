#include <systemc.h>
#include "instructionMemory.h"
#include "TestBench.h"


int sc_main(int argc, char *argv[]) {
  
    sc_signal< sc_bv<32> > pcChannel, instructionMemChannel;

    const sc_time period(10, SC_NS);

    sc_clock clock("clock", period);

    InstructionMemory instMem("instructionMemory");
    TestBench testBench("testBench");

    instMem.instructionDistribution(instructionMemChannel);
    testBench.instructionDistribution(instructionMemChannel);

    instMem.programCounterIndex(pcChannel);
    testBench.programCounterIndex(pcChannel);


    testBench.clock(clock);
    sc_start();
    return 0;
}
