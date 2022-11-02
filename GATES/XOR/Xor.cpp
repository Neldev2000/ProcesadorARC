#include "Xor.h"

XorGate::XorGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;
    }


void XorGate::process() {
    output.write((inA.read() xor inB.read()));
}
