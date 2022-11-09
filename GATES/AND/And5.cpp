#include "And5.h"

AndGate5::AndGate5(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"), inD("inD"), inE("inE"),
    output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD << inE;

    }


void AndGate5::process() {
    output.write(inA.read() and inB.read() and inC.read() and inD.read() and inE.read());
}
