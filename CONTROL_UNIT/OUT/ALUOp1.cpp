#include "ALUOp1.h"

AluOp1::AluOp1(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    andGate4("andGate4"), andGate("andGate"), norGate4("norGate4"), notGate("notGate"), orGate("orGate")
 {
    norGate4.inA(i6);
    norGate4.inB(i5);
    norGate4.inC(i3);
    norGate4.inD(i2);
    norGate4.output(channels[0]); // to andGate

    andGate.inA(channels[0]);
    andGate.inB(i4);    
    andGate.output(channels[1]); // to orGate

    notGate.inA(i4);
    notGate.output(channels[2]); //to andGate4

    andGate4.inA(channels[2]);
    andGate4.inB(i6);
    andGate4.inC(i5);
    andGate4.inD(i2);
    andGate4.output(channels[3]); // to orGate

    orGate.inA(channels[1]);
    orGate.inB(channels[3]);
    orGate.output(s);




}