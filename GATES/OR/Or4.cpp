#include "Or4.h"

OrGate4::OrGate4(sc_module_name modName): 
    sc_module(modName),
    inA("inA"), inB("inB"), inC("inC"), inD("inD")
    ,output("output") {


        SC_METHOD(process);
        sensitive << inA << inB << inC << inD;

    }


void OrGate4::process() {
    output.write(inA.read() or inB.read() or inC.read() or inD);
}
