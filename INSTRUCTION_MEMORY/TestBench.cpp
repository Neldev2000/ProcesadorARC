#include "TestBench.h"

TestBench::TestBench(sc_module_name modName) :
    sc_module(modName),
    programCounterIndex("ProgramCounterIndex"),
    instructionDistribution("InstructionDistribution"),
    clock("Clock")
 {
    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();
}


void TestBench::test() {
    programCounterIndex.write("1");


    wait();
    printData();
    sc_uint<32> data = programCounterIndex.read();
    data += 4;
    programCounterIndex.write(data);
    wait();
    printData();
}
void TestBench::printData() {
    std::cout << "PC Direction       : "<< programCounterIndex.read() << '\n'
              << "Instruction Memory : "<< instructionDistribution.read() << '\n';
}