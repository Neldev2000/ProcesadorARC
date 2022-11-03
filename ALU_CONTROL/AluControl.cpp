#include "AluControl.h"

AluControl::AluControl(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"),aluOp1("ALUOp1"), aluOp2("ALUOp2"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    aluF0("aluF0"), aluF1("aluF1"), aluF2("aluF2"),
    bitRes0("bit0"),
    bitRes1("bit1"),
    bitRes2("bit2")
 {

    bitRes0.aluOp0(aluOp0);
    bitRes0.aluOp1(aluOp1);
    bitRes0.aluOp2(aluOp2);

    bitRes0.i30(i30);
    bitRes0.i14(i14);
    bitRes0.i13(i13);
    bitRes0.i12(i12);

    bitRes0.s(aluF0);

    bitRes1.aluOp0(aluOp0);
    bitRes1.aluOp1(aluOp1);
    bitRes1.aluOp2(aluOp2);

    bitRes1.i30(i30);
    bitRes1.i14(i14);
    bitRes1.i13(i13);
    bitRes1.i12(i12);

    bitRes1.s(aluF1);

    bitRes2.aluOp0(aluOp0);
    bitRes2.aluOp1(aluOp1);
    bitRes2.aluOp2(aluOp2);

    bitRes2.i30(i30);
    bitRes2.i14(i14);
    bitRes2.i13(i13);
    bitRes2.i12(i12);
    
    bitRes2.s(aluF2);

    /*
    /// BIT 0
    bitRes0.aluOp0(channels[0]);
    aluOp0(channels[0]);

    bitRes0.aluOp1(channels[1]);
    aluOp1(channels[1]);

    bitRes0.aluOp2(channels[2]);
    aluOp2(channels[2]);

    i30(channels[3]);
    bitRes0.i30(channels[3]);

    i14(channels[4]);
    bitRes0.i14(channels[4]);

    i13(channels[5]);
    bitRes0.i13(channels[5]);

    i12(channels[6]);
    bitRes0.i12(channels[6]);

    aluF0(channels[7]);
    bitRes0.s(channels[7]);

    /// BIT 1
    bitRes1.aluOp0(channels[8]);
    aluOp0(channels[8]);

    bitRes1.aluOp1(channels[9]);
    aluOp1(channels[9]);

    bitRes1.aluOp2(channels[10]);
    aluOp2(channels[10]);

    i30 (channels[11]);
    bitRes1.i30(channels[11]);

    i14(channels[12]);
    bitRes1.i14(channels[12]);

    i13(channels[13]);
    bitRes1.i13(channels[13]);

    i12(channels[14]);
    bitRes1.i12(channels[14]);

    aluF1(channels[15]);
    bitRes1.s(channels[15]);

    /// BIT 2
    bitRes2.aluOp0(channels[16]);
    aluOp0(channels[16]);

    bitRes2.aluOp1(channels[17]);
    aluOp1(channels[17]);

    bitRes2.aluOp2(channels[18]);
    aluOp2(channels[18]);

    i30(channels[19]);
    bitRes2.i30(channels[19]);

    i14(channels[20]);
    bitRes2.i14(channels[20]);

    i13 (channels[21]);
    bitRes2.i13(channels[21]);

    i12(channels[22]);
    bitRes2.i12(channels[22]);

    aluF2(channels[23]);
    bitRes2.s(channels[23]);
*/
}

