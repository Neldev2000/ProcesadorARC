#include "ExMem.h"


ExMem::ExMem(sc_module_name nm):sc_module(nm),
    adder4("adder4"),
    sumMux("sumMux"),addressDm("addressDm"),
    rp("rp"),writeDataDm("writeDataDm"), zeroAnd("zeroAnd"),brachAnd("brachAnd"),
        memReadDm("memReadDm"),memWriteDm("memWriteDm"),memToRegP("memToRegP"),
        adder4Out("adder4Out") {

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
    adder4Out.write(adder4);
   // immGenBranchOut.write(immGenBranch.read());
    cout << "EXMEN \n";
}