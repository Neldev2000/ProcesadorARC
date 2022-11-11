#include "Adder4.h"

Adder4::Adder4(sc_module_name modName):
    sc_module(modName),
    pcIn("programCounterIn"),
    pcOut("programCounterNextLine"){
        SC_METHOD(process);
        sensitive << pcIn;
        dont_initialize();
}

void Adder4::process() {
    pcOut.write(pcIn.read().to_int() + 4);
}