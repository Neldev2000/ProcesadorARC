#include "Xnor4.h"

XnorGate4::XnorGate4(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"), inD("inD")
    ,output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD;

    }


void XnorGate4::process() {
    output.write(not(inA.read() xor inB.read() xor inC.read() xor inD.read()));
}
