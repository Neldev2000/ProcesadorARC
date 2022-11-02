#include "Or3.h"

OrGate3::OrGate3(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC")
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC;

        dont_initialize();
    }


void OrGate3::process() {
    output.write(inA.read() or inB.read() or inC.read());
}