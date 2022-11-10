#include "MemWb.h"


MemWb::MemWb(sc_module_name nm):sc_module(nm),readDataMux("readDataMux"),
    resMux("res"), memToRegMux("memToRegMux"){
	SC_METHOD(operacion);
    dont_initialize();
    sensitive << readData << res << memToReg;
}

void MemWb::operacion(){
    readDataMux.write(readData.read());
    resMux.write(res.read());
	memToRegMux.write(memToReg.read());
}
