#include "Xor3.h"

XorGate3::XorGate3(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),inC("inC")
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC;

        dont_initialize();
    }


void XorGate3::process() {
    output.write((inA.read() xor inB.read() xor inC.read()));
}