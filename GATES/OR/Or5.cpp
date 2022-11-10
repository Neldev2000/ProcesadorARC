#include "Or5.h"

OrGate5::OrGate5(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"), inD("inD"), inE("inE")
    ,output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD << inE;

    }


void OrGate5::process() {
    output.write(inA.read() or inB.read() or inC.read() or inD.read() or inE.read());
}
