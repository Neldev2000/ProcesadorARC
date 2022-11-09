#include "ALUOp3.h"

AluOp3::AluOp3(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    andGate3("andGate3"), norGate3("norGate3")
 {
    norGate3.inA(i6);
    norGate3.inB(i3);
    norGate3.inC(i2);
    norGate3.output(channels[0]);// to andGate3

    andGate3.inA(channels[0]);
    andGate3.inB(i5);
    andGate3.inC(i4);
    andGate3.output(s);


}