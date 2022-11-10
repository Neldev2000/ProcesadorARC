#include "ALUOp2.h"

AluOp2::AluOp2(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    orGate("orGate"), notGate("notGate"), andGate4("andGate4"), norGate3("norGate3" ), andGate3("andGate3"), xnorGate("xnorGate")
 {
	xnorGate.inA(i3);
	xnorGate.inB(i2);
	xnorGate.output(channels[0]); // to andGate4

	notGate.inA(i4);
	notGate.output(channels[1]); // to andGate4

	andGate4.inA(i6);
	andGate4.inB(i5);
	andGate4.inC(channels[0]);
	andGate4.inD(channels[1]);
	andGate4.output(channels[2]); // to orGAte

	norGate3.inA(i6);
	norGate3.inB(i3);
	norGate3.inC(i2);
	norGate3.output(channels[3]); // to andGAte3

	andGate3.inA(i5);
	andGate3.inB(i4);
	andGate3.inC(channels[3]);
	andGate3.output(channels[4]); // to orGate

	orGate.inA(channels[2]);
	orGate.inB(channels[4]);
	orGate.output(s);


}