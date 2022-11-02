#include "Nor.h"

NorGate::NorGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;

        dont_initialize();
    }


void NorGate::process() {
    output.write(not(inA.read() or inB.read()));
}