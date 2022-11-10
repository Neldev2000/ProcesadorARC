#include "TestBench.h"

TestBench::TestBench(sc_module_name modName) :
    sc_module(modName),
   
    controlUnit("ControlUnit"),
    rs1("rs1"),
    rs2("rs2"),
    rd("rd"),
    immGen("ImmGen"),
    programCounterIndex("ProgramCounterIndex"),
    clock("Clock")
 {
    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();
}


void TestBench::test() {
    programCounterIndex.write("1");


    wait();
   // printData();
    
    
}
void TestBench::printData() {
    cout << "PC Direction      : " << programCounterIndex.read() << '\n'
         << "Control Unit Bits : " << controlUnit.read() << '\n'
         << "Rs1               : " << rs1.read() << '\n'
         << "Rs2               : " << rs2.read() << '\n'
         << "Rd                : " << rd.read()  << '\n'
         << "Imm Gen           : " << immGen.read() << '\n'
         << "============================================================\n\n";
}
