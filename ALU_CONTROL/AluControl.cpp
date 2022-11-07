#include "AluControl.h"

AluControl::AluControl(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"),aluOp1("ALUOp1"), aluOp2("ALUOp2"),aluOp3("aluOp3"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    aluF0("aluF0"), aluF1("aluF1"), aluF2("aluF2"),
    bitRes0("bit0"),
    bitRes1("bit1"),
    bitRes2("bit2")
 {
    ///////////////////////////////
    bitRes0.aluOp0(aluOp0);
    bitRes0.aluOp1(aluOp1);
    bitRes0.aluOp2(aluOp2);
    bitRes0.aluOp3(aluOp3);

    bitRes0.i30(i30);
    bitRes0.i14(i14);
    bitRes0.i13(i13);
    bitRes0.i12(i12);

    bitRes0.s(aluF0);
    ///////////////////////////////

    bitRes1.aluOp3(aluOp3);
    bitRes1.aluOp1(aluOp1);

    bitRes1.i30(i30);
    bitRes1.i14(i14);
    bitRes1.i13(i13);

    bitRes1.s(aluF1);
    ///////////////////////////////
    bitRes2.aluOp3(aluOp3);
    bitRes2.aluOp2(aluOp2);

    bitRes2.i30(i30);
    bitRes2.i14(i14);
    bitRes2.i13(i13);
    bitRes2.i12(i12);

    bitRes2.s(aluF);

}

