#include "And.h"

AndGate::AndGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;
    }


void AndGate::process() {
    output.write(inA.read() and inB.read());
}
