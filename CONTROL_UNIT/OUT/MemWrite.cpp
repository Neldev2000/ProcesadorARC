#include "MemWrite.h"

MemWrite::MemWrite(sc_module_name modName):
    sc_module(modName)
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    andGate("andGate"), norGate4("norGate4")
 {

    norGate4.inA(i6);
    norGate4.inB(i4);
    norGate4.inC(i3);
    norGate4.inD(i2);
    norGate4.output(channels[0]); 

    andGate.inA(i5);
    andGate.inB(channels[0]);
    andGate.output(s);

}