#include "RegWrite.h"

RegWrite::RegWrite(sc_module_name modName): 
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    andGates("andGates",2),
    norGate3("norGate3"),
    andGate4("andGate4"),
    notGates("notGates",2),
    orGates("orGates",2)
{

    notGates[0].inA(i5);
    notGates[0].output(channels[0]); // to orGates[0]

    orGates[0].inA(channels[0]);
    orGates[0].inB(i4);
    orGates[0].output(channels[1]); // to andGates[0]

    norGate3.inA(i6);
    norGate3.inB(i3);
    norGate3.inC(i2);
    norGate3.output(channels[2]); // to andGates[0]

    andGates[0].inA(channels[1]);
    andGates[0].inB(channels[2]);
    andGates[0].output(channels[3]); // to orGates[1]

    notGates[1].inA(i4);
    notGates[1].output(channels[4]); //To andGate4

    andGate4.inA(channels[4]);
    andGate4.inB(i6);
    andGate4.inC(i5);
    andGate4.inD(i3);
    andGate4.output(channels[5]); // To andGate[1]

    andGates[1].inA(channels[5]);
    andGates[1].inB(i2);
    andGates[1].output(channels[6]); // to orGate

    orGates[1].inA(channels[3]);
    orGates[1].inB(channels[6]);
    orGates[1].output(s);




}