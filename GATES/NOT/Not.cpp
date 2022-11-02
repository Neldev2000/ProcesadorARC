#include "Not.h"

NotGate::NotGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), 
    output("output") {


        SC_METHOD(process);
        sensitive << inA;
    }


void NotGate::process() {
    output.write(not(inA.read()));
}
