#include "Or.h"

OrGate::OrGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;

    }


void OrGate::process() {
    output.write(inA.read() or inB.read());
}
