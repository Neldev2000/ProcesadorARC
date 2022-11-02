#include "Output1.h"

Output1::Output1(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    norGates("norGates", 2),
    andGates("andGates", 2),
    andGates3("andGates3", 2),
    notGates("notGates", 2),
    xnorGate("xnorGate"),
    orGate4("orGate4")
{
    norGates[0].inA(i12);
    norGates[0].inB(i14);
    norGates[0].output(channels[0]);

    notGates[0].inA(i13);
    notGates[0].output(channels[1]);

    xnorGate.inA(i12);
    xnorGate.inB(i14);
    xnorGate.output(channels[2]);

    notGates[1].inA(i30);
    notGates[1].output(channels[3]);

    andGates3[0].inA(channels[0]);
    andGates3[0].inB(channels[1]);
    andGates3[0].inC(i30);
    andGates3[0].output(channels[4]);

    andGates3[1].inA(channels[2]);
    andGates3[1].inB(channels[3]);
    andGates3[1].inC(i13);
    andGates3[1].output(channels[5]);

    ////////////////////////////

    norGates[1].inA(aluOp0);
    norGates[1].inB(aluOp1);
    norGates[1].output(channels[6]);

    andGates[0].inA(channels[6]);
    andGates[0].inB(aluOp1);
    andGates[0].output(channels[7]);

    andGates[1].inA(aluOp0);
    andGates[1].inB(aluOp1);
    andGates[1].output(channels[8]);

    orGate4.inA(channels[7]);
    orGate4.inB(channels[8]);
    orGate4.inC(channels[5]);
    orGate4.inD(channels[4]);
    orGate4.output(s);



}