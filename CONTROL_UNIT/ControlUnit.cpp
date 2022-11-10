#include "ControlUnit.h"

ControlUnit::ControlUnit(sc_module_name modName):
 sc_module(modName),
 i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
 regWrite("regWrite"), memWrite("memWrite"), memToReg("memToReg"), memRead("memRead"), branch("branch"), 
 aluSrc("aluSrc"), aluOp2("aluOp2"), aluOp1("aluOp1"), aluOp0("aluOp0"),

 _regWrite("_regWrite"), _memWrite("_memWrite"), _memToReg("_memToReg"), _memRead("_memRead"), _branch("_branch"), 
 _aluSrc("_aluSrc"), _aluOp2("_aluOp2"), _aluOp1("_aluOp1"), _aluOp0("_aluOp0")
 {

    //////////// REGWRITE
    _regWrite.i6(i6);
    _regWrite.i5(i5);
    _regWrite.i4(i4);
    _regWrite.i3(i3);
    _regWrite.i2(i2);
    _regWrite.s(regWrite);

    /////////// MemWRITE
    _memWrite.i6(i6);
    _memWrite.i5(i5);
    _memWrite.i4(i4);
    _memWrite.i3(i3);
    _memWrite.i2(i2);
    _memWrite.s(memWrite);

     /////////// MemtoReg
    _memToReg.i6(i6);
    _memToReg.i5(i5);
    _memToReg.i4(i4);
    _memToReg.i3(i3);
    _memToReg.i2(i2);
    _memToReg.s(memToReg);

    /////////// _memRead
    _memRead.i6(i6);
    _memRead.i5(i5);
    _memRead.i4(i4);
    _memRead.i3(i3);
    _memRead.i2(i2);
    _memRead.s(memRead);

    /////////// _memRead
    _branch.i6(i6);
    _branch.i5(i5);
    _branch.i4(i4);
    _branch.i3(i3);
    _branch.s(branch);

   /////////// _memRead
    _aluSrc.i6(i6);
    _aluSrc.i5(i5);
    _aluSrc.i4(i4);
    _aluSrc.i3(i3);
    _aluSrc.i2(i2);
    _aluSrc.s(aluSrc);


    ////////// _memRead
    _aluOp2.i6(i6);
    _aluOp2.i5(i5);
    _aluOp2.i4(i4);
    _aluOp2.i3(i3);
    _aluOp2.i2(i2);
    _aluOp2.s(aluOp2);

    ////////// _memRead
    _aluOp1.i6(i6);
    _aluOp1.i5(i5);
    _aluOp1.i4(i4);
    _aluOp1.i3(i3);
    _aluOp1.i2(i2);
    _aluOp1.s(aluOp1);

    ////////// _memRead
    _aluOp0.i6(i6);
    _aluOp0.i5(i5);
    _aluOp0.i4(i4);
    _aluOp0.i3(i3);
    _aluOp0.i2(i2);
    _aluOp0.s(aluOp0);

    

}