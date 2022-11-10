#include "ALUOp1.h"

AluOp1::AluOp1(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    xnorGate("xnorGate"), norGate("norGate"), andGates3("andGates3",2), norGate3("norGate3"), orGate("orGate")
 {
    xnorGate.inA(i6);
    xnorGate.inB(i2);
    xnorGate.output(channels[0]); // to andGates3[0]

    norGate.inA(i4);
    norGate.inB(i3);
    norGate.output(channels[1]); //to andGates3[0]

    andGates3[0].inA(i5);
    andGates3[0].inB(channels[0]);
    andGates3[0].inC(channels[1]);
    andGates3[0].output(channels[2]); // to orGate

    norGate3.inA(i6);
	norGate3.inB(i3);
	norGate3.inC(i2);
	norGate3.output(channels[3]); // to andGAte3

	andGates3[1].inA(i5);
	andGates3[1].inB(i4);
	andGates3[1].inC(channels[3]);
	andGates3[1].output(channels[4]); // to orGate

	orGate.inA(channels[2]);
	orGate.inB(channels[4]);
	orGate.output(s);



}