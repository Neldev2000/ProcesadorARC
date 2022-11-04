#include "Output1.h"

Output1::Output1(sc_module_name modName):
    sc_module(modName),
    aluOp3("aluOp3"), aluOp1("ALUOp1"),
    i30("i30"), i14("i14"), i13("i13"),
    s("output"),
    notGates("notGates",2),
    andGate("andGate"),
    andGate4("andGate4"),
    orGate("orGate")
{
    
    notGates[0].inA(aluOp3);
    notGates[0].output(channels[0]);

    andGate.inA(channels[0]);
    andGate.inB(aluOp1);
    andGate.output(channels[1]);

    notGates[1].inA(i30);
    notGates[1].output(channels[2]);

    andGate4.inA(aluOp3);
    andGate4.inB(channels[2]);
    andGate4.inC(i14);
    andGate4.inD(i13);
    andGate.output(channels[3]);

    orGate.inA(channels[3]);
    orGate.inB(channels[1]);
    orGate.output(s);


}