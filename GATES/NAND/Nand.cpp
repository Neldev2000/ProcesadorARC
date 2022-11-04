#include "Nand.h"

NandGate::NandGate(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB;
    }


void NandGate::process() {
    output.write(not(inA.read() and inB.read()));
}
