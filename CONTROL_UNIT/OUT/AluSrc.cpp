#include "AluSrc.h"

AluSrc::AluSrc(sc_module_name modName):
 sc_module(modName),
 i6("i6"), i5("i5") i4("i4"), i3("i3"), i2("i2"),
 s("output"),
 andGate("andGate"), andGate4("andGate4"), notGate("notGate"), norGate3("norGate3"), nandGate("nandGate")
 {
    norGate3.inA(i6);
    norGate3.inB(i3);
    norGate3.inC(i2);
    norGate3.output(channels[0]); // To andGate

    nandGate.inA(i5);
    nandGate.inB(i4);
    nandGate.output(channels[1]); // To andGate

    andGate.inA(channels[0]);
    andGate.inB(channels[1]);
    andGate.output(channels[2]); // To orGate

    notGate.inA(i4);
    notGate.output(channels[3]); //To andGate4

    andGate4.inA(channels[3]);
    andGate4.inB(i6);
    andGate4.inC(i5);
    andGate4.inD(i2);
    andGate4.output(channels[4]); // To orGate

    orGate.inA(channels[2]);
    orGate.inB(channels[4]);
    orGate.output(s);

}