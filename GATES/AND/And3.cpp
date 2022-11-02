#include "And3.h"

AndGate3::AndGate3(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC;
    }


void AndGate3::process() {
    output.write(inA.read() and inB.read() and inC.read());
}
