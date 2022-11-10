#include "Output2.h"

Output2::Output2(sc_module_name modName):
    sc_module(modName),
    aluOp2("aluOp2"), aluOp1("aluOp1"), aluOp0("aluOp0"),  
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    norGate4("norGate4"),
    xorGates("xorGate"),
    xnorGate("xnorGate"),
    andGates("andGate",4) ,
    notGates("notGates", 2),
    norGate("norGate"),
    orGate("orGate"),
    andGate4("andGate4"),
    orGate3("orGate3")
{
    norGate4.inA(aluOp2);
    norGate4.inB(aluOp1);
    norGate4.inC(aluOp0);
    norGate4.inD(i14);
    norGate4.output(channels[0]); //to andGates[0]

    xorGates.inA(i13);
    xorGates.inB(i12);
    xorGates.output(channels[1]); // to andGates[0]

    andGates[0].inA(channels[0]);
    andGates[0].inB(channels[1]);
    andGates[0].output(channels[2]); // to orGate4

    //////////////////////////////////////////////////

    notGates[0].inA(aluOp1);
    notGates[0].output(channels[3]); // to andGates[1]

    andGates[1].inA(aluOp2);
    andGates[1].inB(channels[3]);
    andGates[1].output(channels[4]); //to orGate4

    //////////////////////////////////////////////////

    xnorGate.inA(i14);
    xnorGate.inB(i13);
    xnorGate.output(channels[5]); // to andGates[2]

    andGates[2].inA(channels[5]);
    andGates[2].inB(i12);
    andGates[2].output(channels[6]); // to orGate

    norGate.inA(i14);
    norGate.inB(i12);
    norGate.output(channels[7]); // to andGates[3]

    andGates[3].inA(channels[7]);
    andGates[3].inB(i13);
    andGates[3].output(channels[8]); //to orGate

    orGate.inA(channels[8]);
    orGate.inB(channels[6]);
    orGate.output(channels[9]); //to andGate 4

    notGates[1].inA(i30);
    notGates[1].output(channels[10]);//to andGate4

    andGate4.inA(aluOp2);
    andGate4.inB(aluOp1);
    andGate4.inC(channels[9]);
    andGate4.inD(channels[10]);
    andGate4.output(channels[11]); //to orGate4

    //////////////////////////////////////////////////

    orGate3.inA(channels[2]);
    orGate3.inB(channels[4]);
    orGate3.inC(channels[11]);
    orGate3 .output(s);

}