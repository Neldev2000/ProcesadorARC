#include "Xnor.h"

XnorGate::XnorGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;
    }


void XnorGate::process() {
    output.write(not(inA.read() xor inB.read()));
}
