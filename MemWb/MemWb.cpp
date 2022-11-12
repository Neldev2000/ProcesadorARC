#include "MemWb.h"


MemWb::MemWb(sc_module_name nm):sc_module(nm),
    adder4("adder4"), immGenBranch("immGenBranch"),
    andGate("andGate")
    ,readDataMux("readDataMux"),
    resMux("res"), memToRegMux("memToRegMux"),
    adder4Out("adder4Out"), immGenBranchOut("immGenBranchOut"),
    andGateOut("andGateOut"){
	SC_METHOD(operacion);
    
    sensitive << readData << res << memToReg << adder4 <<immGenBranch <<andGate;
    dont_initialize();
}

void MemWb::operacion(){
    readDataMux.write(readData.read());
    resMux.write(res.read());
	memToRegMux.write(memToReg.read());
    adder4Out.write(adder4.read());
    immGenBranchOut.write(immGenBranch.read());
    andGateOut.write(andGate.read());
}
