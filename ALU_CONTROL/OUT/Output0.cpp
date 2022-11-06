#include "Output0.h"

Output0::Output0(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2"), aluOp3("aluOp3"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    notGates("notGates",3),
   andGates3("andGates3", 2),
   andGates("andGates", 2),
   orGates("orGates", 3),
   nandGate("nandGate"),
   norGate3("norGate3")
{

    notGates[0].inA(aluOp3);
    notGates[0].output(channels[0]);

    nandGate.inA(aluOp2);
    nandGate.inB(aluOp1);
    nandGate.output(channels[1]);

    andGates3[0].inA(channels[0]);
    andGates3[0].inB(channels[1]);
    andGates3[0].inC(aluOp0);
    andGates3[0].output(channels[2]);

    /////////////////////////////////////
    /////////////////////////////////////

    notGates[1].inA(i12);
    notGates[1].output(channels[3]);

    norGate3.inA(i14);
    norGate3.inB(i13);
    norGate3.inC(i12);
    norGate3.output(channels[4]);

    orGates[0].inA(i14);
    orGates[0].inB(channels[3]);
    orGates[0].output(channels[5]);

    notGates[2].inA(i30);
    notGates[2].output(channels[6]);

    andGates3[1].inA(channels[6]);
    andGates3[1].inB(channels[5]);
    andGates3[1].inC(i13);
    andGates3[1].output(channels[7]);

    andGates[0].inA(i30);
    andGates[0].inB(channels[4]);
    andGates[0].output(channels[8]);

    orGates[1].inA(channels[7]);
    orGates[1].inB(channels[8]);
    orGates[1].output(channels[9]);

    andGates[1].inA(channels[9]);
    andGates[1].inB(aluOp3);
    andGates[1].output(channels[10]);

    orGates[2].inA(channels[10]);
    orGates[2].inB(channels[2]);
    orGates[2].output(s);


}