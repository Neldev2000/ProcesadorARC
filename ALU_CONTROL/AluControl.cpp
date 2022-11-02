#include "AluControl.h"

AluControl::AluControl(sc_module_name modName):
    sc_module(modName),
    aluOp("ALUOp"),
    instruction("instruction"),
    aluFunction("aluFunction")
 {
    SC_METHOD(process);
    sensitive << instruction << aluOp;
}
void AluControl::process() {
    buildS0();
    buildS1();
    buildS2();
}