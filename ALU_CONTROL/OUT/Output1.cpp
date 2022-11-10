#include "Output1.h"

Output1::Output1(sc_module_name modName):
    sc_module(modName),
    aluOp2("aluOp2"), aluOp1("aluOp1"), aluOp0("ALUOp0"),
    i30("i30"), i14("i14"), i13("i13"),i12("i12"),
    s("output"),
    andGate5("andGate5"),
    andGates3("andGates3",3),
    notGates("notGates", 2),
    norGates("norGates", 3),
    orGate("norGates"),
    andGate("andGate"),
    orGate3("orGate3")
{
    
    notGates[0].inA(i30);
    notGates[0].output(channels[0]); // to andGate5

    andGate5.inA(aluOp2);
    andGate5.inB(aluOp1);
    andGate5.inC(channels[0]);
    andGate5.inD(i14);
    andGate5.inE(i13);
    andGate5.output(channels[1]); // to orGate 3

    //////////////////////////////////////////////

    notGates[1].inA(aluOp1);
    notGates[1].output(channels[2]); // to andGates3[0]

    andGates3[0].inA(aluOp2);
    andGates3[0].inB(channels[2]);
    andGates3[0].inC(aluOp0);
    andGates3[0].output(channels[3]); //to orGate 3

    //////////////////////////////////////////////

    norGates[0].inA(aluOp2);
    norGates[0].inB(aluOp1);
    norGates[0].output(channels[4]); //to andGate

    norGates[1].inA(i14);
    norGates[1].inB(i13);
    norGates[1].output(channels[5]); //to andGates3[1]

    andGates3[1].inA(aluOp0);
    andGates3[1].inB(i12);
    andGates3[1].inC(channels[5]);
    andGates3[1].output(channels[6]); //to orGate

    norGates[2].inA(aluOp0);
    norGates[2].inB(i12);
    norGates[2].output(channels[7]); //to andGates3[2]

    andGates3[2].inA(i14);
    andGates3[2].inB(i13);
    andGates3[2].inC(channels[7]);
    andGates3[2].output(channels[8]);

    orGate.inA(channels[6]);
    orGate.inB(channels[8]);
    orGate.output(channels[9]); //to andGate

    andGate.inA(channels[4]);
    andGate.inB(channels[9]);
    andGate.output(channels[10]); //to orGate3


    //////////////////////////////////////////////
    orGate3.inA(channels[1]);
    orGate3.inB(channels[3]);
    orGate3.inC(channels[10]);
    orGate3.output(s);

}