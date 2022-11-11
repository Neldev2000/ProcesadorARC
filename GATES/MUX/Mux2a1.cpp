#include "Mux2a1.h"

Mux2a1::Mux2a1(sc_module_name modName):
    sc_module(modName),
    inA("inputA"),
    inB("inputB"),
    output("output")
 {
    SC_METHOD(process);
    sensitive << controlSignal << inA << inB;
}

void Mux2a1::process() {
    output.write( (controlSignal == true? inA.read() : inB.read()) );
}