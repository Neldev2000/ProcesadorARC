#include "Nor4.h"

NorGate4::NorGate4(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"),inC("inC"), inD("inD")
    output("output") {


        SC_METHOD(process);
        sensitive << inA, inB << inC << inD;

        dont_initialize();
    }


void NorGate4::process() {
    output.write(not(inA.read() or inB.read() or inC.read() or inD.read()));
}