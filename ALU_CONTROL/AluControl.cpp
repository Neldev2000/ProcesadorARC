#include "AluControl.h"

AluControl::AluControl(sc_module_name modName):
    sc_module(modName),
    aluOp("ALUOp"),
    instruction("instruction"),
    aluFunction("ALUFunction"),
    bitRes0("bit0")
   // bitRes1("bit1"),
    //bitRes2("bit2")
 {
    SC_METHOD(process);
    sensitive << aluOp << instruction;
}

void AluControl::process() {
    bitRes0.aluOp0.write(aluOp.read().range(2,2).to_int());
    bitRes0.aluOp1.write(aluOp.read().range(1,1).to_int());
    bitRes0.aluOp2.write(aluOp.read().range(0,0).to_int());

    bitRes0.i30.write(instruction.read().range(30,30).to_int());
    bitRes0.i14.write(instruction.read().range(14,14).to_int());
    bitRes0.i13.write(instruction.read().range(13,13).to_int());
    bitRes0.i12.write(instruction.read().range(12,12).to_int());

    aluFunction.write( bitRes0.s.read() );

}
