#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
/* code */
#include <systemc.h>


#include "RegWrite.h"
#include "MemWrite.h"
#include "MemtoReg.h"
#include "MemRead.h"
#include "Branch.h"
#include "AluSrc.h"
#include "ALUOp3.h"
#include "ALUOp2.h"
#include "ALUOp1.h"
#include "ALUOp0.h"

class ControlUnit : public sc_module
{
public:
    SC_CTOR(ControlUnit);
    sc_in<bool> i6, i5, i4, i3, i2;
    sc_out<bool> regWrite, memWrite, memToReg, memRead, branch, aluSrc, aluOp3, aluOp2, aluOp1, aluOp0;
private:
    RegWrite _regWrite;
    MemWrite _memWrite;
    MemtoReg _memToReg;
    MemRead  _memRead;
    Branch   _branch;
    AluSrc   _aluSrc;
    AluOp3   _aluOp3;
    AluOp2   _aluOp2;
    AluOp1   _aluOp1;
    AluOp0   _aluOp0;
};


#endif //CONTROL_UNIT_H
