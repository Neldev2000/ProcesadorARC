#include "Output2.h"

Output2::Output2(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    andGates("andGates", 5),
    notGates("notGates", 2),
    orGate("orGate"),
    orGate3("orGate3"),
    norGate("norGate"),
    norGate4("norGate4")
    
{
    norGate.inA(i13);
    norGate.inB(i14);
    norGate.output(channels[0]);

    notGates[0].inA(i12);
    notGates[0].output(channels[1]);

    andGates[0].inA(i12);
    andGates[0].inB(channels[0]);
    andGates[0].output(channels[2]);

    andGates[1].inA(channels[1]);
    andGates[1].inB(i13);
    andGates[1].output(channels[3]);

    orGate.inA(channels[2]);
    orGate.inB(channels[3]);
    orGate.output(channels[4]);

    norGate4.inA(aluOp0);
    norGate4.inB(aluOp1);
    norGate4.inC(aluOp2);
    norGate4.inD(i30);
    norGate4.output(channels[5]);

    andGates[2].inA(channels[4]);
    andGates[2].inB(channels[5]);
    andGates[2].output(channels[6]);

    notGates[1].inA(aluOp1);
    notGates[1].output(channels[7]);

    andGates[3].inA(aluOp1);
    andGates[3].inB(aluOp2);
    andGates[3].output(channels[8]);

    andGates[4].inA(aluOp0);
    andGates[4].inB(channels[7]);
    andGates[4].output(channels[9]);


    orGate3.inA(channels[6]);
    orGate3.inB(channels[8]);
    orGate3.inC(channels[9]);
    orGate3.output(s);
}