#include "Nor3.h"

NorGate3::NorGate3(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),inC("inC")
    ,output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC;

    }


void NorGate3::process() {
    output.write(not(inA.read() or inB.read() or inC.read()));
}
