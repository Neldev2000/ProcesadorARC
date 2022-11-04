#include "Output2.h"

Output2::Output2(sc_module_name modName):
    sc_module(modName),
    aluOp3("aluOp3"), aluOp2("aluOp2"), 
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    andGates("andGates", 3),
    notGates("notGates", 2),
    orGates("orGates", 2),
    andGate3("andGate3"),
    xnorGate("xnorGate"),
    norGate("norGate")   
{
    notGates[0].inA(aluOp3);
    notGates[0].output(channels[0]);

    andGates[0].inA(channels[0]);
    andGates[0].inB(aluOp2);
    andGates[0].output(channels[1]);

    xnorGate.inA(i14);
    xnorGate.inB(i13);
    xnorGate.output(channels[2]);

    norGate.inA(i14);
    norGate.inB(i12);
    norGate.output(channels[3]);

    andGates[1].inA(channels[2]);
    andGates[1].inB(i12);
    andGates[1].output(channels[4]);

    andGates[2].inA(channels[3]);
    andGates[2].inB(i13);
    andGates[2].output(channels[5]);

    orGates[0].inA(channels[4]);
    orGates[0].inB(channels[5]);
    orGates[0].output(channels[6]);

    notGates[1].inA(i30);
    notGates[1].output(channels[7]);

    andGate3.inA(channels[7]);
    andGate3.inB(channels[6]);
    andGate3.inC(aluOp3);
    andGate3.output(channels[8]);



    orGates[1].inA(channels[1]);
    orGates[1].inB(channels[8]);
    orGates[1].output(s);


}