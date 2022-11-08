#include "RegWrite.h"

RegWrite::RegWrite(sc_module_name modName): 
    sc_module(modName),
    i6("i6"), i5("i5") i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    notGates("notGates",3),
    orGates("orGates", 3),
    andGate("andGate"),
    andGate3("andGate3"),
    norGate3("norGate3")
{
    notGates[0].inA(i5);
    notGates[0].output(channels[0]); // To orGates[0]

    orGates[0].inA(channels[0]);
    orGates[0].inB(i4);
    orGates[0].output(channels[1]); // To andGate

    norGate3.inA(i6);
    norGate3.inB(i3);
    norGate3.inC(i2);
    norGate3.output(channels[2]); // To andGate

    andGate.inA(channels[1]);
    andGate.inB(channels[2]);
    andGate.output(channels[3]); // To orGates[2]

    notGates[1].inA(i3);
    notGates[1].output(channels[4]); // to orGates[1]

    orGates[1].inA(channels[4]);
    orGates[1].inB(i2);
    orGates[1].output(channels[5]); // to andGate4

    notGates[2].inA(i4);
    notGates[2].output(channels[6]); // to andGate4

    andGate4.inA(channels[5]);
    andGate4.inB(channels[6]);
    andGate4.inC(i6);
    andGate4.inD(i5);
    andGate4.output(channels[7]); // to orGates[2];

    orGates[2].inA(channels[3]);
    orGates[2].inB(channels[7]);
    orGates[2].output(s);




}