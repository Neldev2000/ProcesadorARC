#include "ALUOp0.h"

AluOp0::AluOp0(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    norGate4("norGate4"), andGate("andGate"), norGate("norGate"), andGate3("andGate3"), orGate("orGate")
 {
    norGate4.inA(i6);
    norGate4.inB(i5);
    norGate4.inC(i3);
    norGate4.inD(i2);
    norGate4.output(channels[0]); // to andGate

    andGate.inA(channels[0]);
    andGate.inB(i4);
    andGate.output(channels[1]); // to orGate

    norGate.inA(i4);
    norGate.inB(i3);
    norGate.output(channels[2]); // to andGate3

    andGate3.inA(i6);
    andGate3.inB(i5);
    andGate3.inC(channels[2]);
    andGate3.output(channels[3]); // to orGate

    orGate.inA(channels[1]);
    orGate.inB(channels[3]);
    orGate.output(s);



}