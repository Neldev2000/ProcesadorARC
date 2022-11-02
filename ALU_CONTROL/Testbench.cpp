#include "Testbench.h"

Testbench::Testbench(sc_module_name modName):
    sc_module(modName),
    instruction("instruction"),
    aluOp("aluOp"),
    aluFunction("aluFunction"),
    clock("clock")
{

    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();

}

void Testbench::test() {
    aluOp.write("000");
    instruction.write("11");

    wait();
    print();
}
void Testbench::print() {
    cout << setw(2) << aluFunction.read() << " | \n";

}

