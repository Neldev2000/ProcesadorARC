#include "Xor4.h"

XorGate4::XorGate4(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),inC("inC"), inD("inD")
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD;

        dont_initialize();
    }


void XorGate4::process() {
    output.write((inA.read() xor inB.read() xor inC.read() xor inD.read()));
}