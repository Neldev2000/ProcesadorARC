#include "Xnor3.h"

XnorGate3::XnorGate3(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC")
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC;

        dont_initialize();
    }


void XnorGate3::process() {
    output.write(not(inA.read() xor inB.read() xor inC.read()));
}