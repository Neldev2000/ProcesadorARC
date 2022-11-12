#include "ExMem.h"


ExMem::ExMem(sc_module_name nm):sc_module(nm),
    sumMux("sumMux"),addressDm("addressDm"),
    rp("rp"),writeDataDm("writeDataDm"), zeroAnd("zeroAnd"),brachAnd("brachAnd"),
        memReadDm("memReadDm"),memWriteDm("memWriteDm"),memToRegP("memToRegP"){

	SC_METHOD(operacion);
   
    sensitive  <<sum<<zero<<res<<readData2<<brach<<memRead<<memWrite<<memToReg;
     dont_initialize();
}

void ExMem::operacion(){
    

    sumMux.write(sum.read());
    zeroAnd.write(zero.read());
	addressDm.write(res.read());
    writeDataDm.write(readData2.read());
    rp.write(res.read());

    brachAnd.write(brach.read());
	memReadDm.write(memRead.read());
    memWriteDm.write(memWrite.read());
    memToRegP.write(memToReg.read());
   
    cout << "EXMEN \n";
}