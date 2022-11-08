#include "Branch.h"

Branch::Branch(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    andGate3("andGate3"), norGate("norGate") {

        norGate.inA(i4);
        norGate.inB(i3);
        norGate.output(channels[0]); // To andGate3

        andGate3.inA(i6);
        andGate3.inB(i5);
        andGate3.inC(channels[0]);
        andGate3.output(s);



}