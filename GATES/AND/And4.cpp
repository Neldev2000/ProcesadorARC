#include "And4.h"

AndGate4::AndGate4(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"), inD("inD"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD;

        dont_initialize();
    }


void AndGate4::process() {
    output.write(inA.read() and inB.read() and inC.read() and inD.read());
}
