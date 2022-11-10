#include "Output0.h"

Output0::Output0(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"), aluOp1("ALUOp1"), aluOp2("ALUOp2"), 
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    s("output"),
    norGate5("norGate5"),
    andGates("andGates",3),
    norGate4("norGate4"),
    norGate("norGate",2),
    andGate4("andGate4"),
    xorGate("xorGate"),
    notGate("notGate"),
    andGate5("andGate5"),
    orGate5("orGate5")
{

    norGate5.inA(aluOp2);
    norGate5.inB(aluOp1);
    norGate5.inC(i14);
    norGate5.inD(i13);
    norGate5.inE(i12);
    norGate5.output(channels[0]); //to andGates[0]

    andGates[0].inA(channels[0]);
    andGates[0].inB(aluOp0);
    andGates[0].output(channels[1]); // to orGate5

    //////////////////////////////////////

    norGate4.inA(aluOp2);
    norGate4.inB(aluOp1);
    norGate4.inC(aluOp0);
    norGate4.inD(i12);
    norGate4.output(channels[2]); // to andGates[1]

    andGates[1].inA(i13);
    andGates[1].inB(channels[2]);
    andGates[1].output(channels[3]); //to orGate5

    //////////////////////////////////////
    norGate[0].inA(aluOp1);
    norGate[0].inB(aluOp0);
    norGate[0].output(channels[4]); //to andGates[2]

    andGates[2].inA(aluOp2);
    andGates[2].inB(channels[4]);
    andGates[2].output(channels[5]); //to orGate5

    //////////////////////////////////////

    xorGate.inA(i30);
    xorGate.inB(i13);
    xorGate.output(channels[6]); // to andGate4

    norGate[1].inA(i14);
    norGate[1].inB(i12);
    norGate[1].output(channels[7]); //to andGate4

    andGate4.inA(aluOp2);
    andGate4.inB(aluOp1);
    andGate4.inC(channels[6]);
    andGate4.inD(channels[7]);
    andGate4.output(channels[8]); //to orGate5

    //////////////////////////////////////
    notGate.inA(i30);
    notGate.output(channels[9]); //to andGate5

    andGate5.inA(channels[9]);
    andGate5.inB(aluOp2);
    andGate5.inC(aluOp1);
    andGate5.inD(i14);
    andGate5.inE(i13);
    andGate5.output(channels[10]); //to orGate5

    //////////////////////////////////////
    orGate5.inA(channels[1]);
    orGate5.inB(channels[3]);
    orGate5.inC(channels[5]);
    orGate5.inD(channels[8]);
    orGate5.inE(channels[10]);
    orGate5.output(s);

}