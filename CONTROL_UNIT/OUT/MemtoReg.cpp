#include "MemtoReg.h"

MemtoReg::MemtoReg(sc_module_name modName) :
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    s("output"),
    norGate5("norGate5")
 {
    norGate5.inA(i6);
    norGate5.inB(i5);
    norGate5.inC(i4);
    norGate5.inD(i3);
    norGate5.inE(i2);
    norGate5.output(s);
    

}