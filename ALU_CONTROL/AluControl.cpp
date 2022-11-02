#include "AluControl.h"

AluControl::AluControl(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2") 
    instruction("instruction"),
    aluFunction0("ALUFunction0"), aluFunction1("ALUFunction1"), aluFunction2("ALUFunction2")
 {
    SC_METHOD(process);
    sensitive << instruction << aluOp;
}
void AluControl::process() {
    buildS0();
    buildS1();
    buildS2();
}