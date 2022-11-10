#include "ALUOp0.h"

AluOp0::AluOp0(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    norGate5("norgate5"), andGate4("andGate4"), notGate("notGate"), orGate("orGate")
 {
    norGate5.inA(i6);
    norGate5.inB(i5);
    norGate5.inC(i4);
    norGate5.inD(i3);
    norGate5.inE(i2);
    norGate5.output(channels[0]); // to orGate

    notGate.inA(i4);
    notGate.output(channels[1]); // to andGate4

    andGate4.inA(i6);
    andGate4.inB(i5);
    andGate4.inC(channels[1]);
    andGate4.inD(i2);
    andGate4.output(channels[2]); //to orGate

    orGate.inA(channels[0]);
    orGate.inB(channels[2]);
    orGate.output(s);



}