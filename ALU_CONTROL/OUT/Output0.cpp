#include "Output0.h"

Output0::Output0(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    andGates("andGates", 2),
    andGates3("andGates3", 2),
    orGate("orGate"),
    orGate3("orGate3"),
    norGate4("norGate4"),
    norGate("norGate"),
    notGate("notGate"),
    xorGate("xorGate")
{

    andGates3[0].inA(i12);
    andGates3[0].inB(i13);
    andGates3[0].inC(i14);
    andGates3[0].output(channels[1]);

    norGate.inA(i13);
    norGate.inB(i14);
    norGate.output(channels[0]);

    orGate.inA(channels[0]);
    orGate.inB(channels[1]);
    orGate.output(channels[2]);

    norGate4.inA(aluOp0);
    norGate4.inB(aluOp1);
    norGate4.inC(aluOp2);
    norGate4.inD(i30);
    norGate4.output(channels[3]);

    andGates[0].inA(channels[3]);
    andGates[0].inB(channels[2]);
    andGates[0].output(channels[6]);

    xorGate.inA(aluOp0);
    xorGate.inB(aluOp2);
    xorGate.output(channels[4]);

    notGate.inA(aluOp1);
    notGate.output(channels[5]);

    andGates[1].inA(channels[4]);
    andGates[1].inB(channels[5]);
    andGates[1].output(channels[7]);

    andGates3[1].inA(aluOp0);
    andGates3[1].inB(aluOp1);
    andGates3[1].inC(aluOp1);
    andGates3[1].output(channels[8]);

    orGate3.inA(channels[6]);
    orGate3.inB(channels[7]);
    orGate3.inC(channels[8]);
    orGate3.output(s);


}