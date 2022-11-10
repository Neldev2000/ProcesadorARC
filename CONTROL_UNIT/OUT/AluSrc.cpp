#include "AluSrc.h"

AluSrc::AluSrc(sc_module_name modName):
 sc_module(modName),
 i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
 s("output"),
 andGates("andGates", 2), andGate4("andGate4"), notGate("notGate"), norGate3("norGate3"), nandGate("nandGate"), orGate("orGate")
 {
    norGate3.inA(i6);
    norGate3.inB(i3);
    norGate3.inC(i2);
    norGate3.output(channels[0]); // To andGate

    nandGate.inA(i5);
    nandGate.inB(i4);
    nandGate.output(channels[1]); // To andGate

    andGates[0].inA(channels[0]);
    andGates[0].inB(channels[1]);
    andGates[0].output(channels[2]); // To orGate

    notGate.inA(i4);
    notGate.output(channels[3]); //To andGate4

    andGate4.inA(channels[3]);
    andGate4.inB(i6);
    andGate4.inC(i5);
    andGate4.inD(i3);
    andGate4.output(channels[4]); // To andGate[1]

    andGates[1].inA(channels[4]);
    andGates[1].inB(i2);
    andGates[1].output(channels[5]); // to orGate

    orGate.inA(channels[2]);
    orGate.inB(channels[5]);
    orGate.output(s);

}