#include "testbench.h"
using namespace std;

testbench::testbench(sc_module_name modName) :
    sc_module(modName),
   
    intb("intb"),
    outtb("outtb"),
    clock("Clock")
 {
    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();
}


void testbench::test() {
    sc_bv<32> sd;

    sd=intb.read();
    outtb.write("011111011111");


    wait();
    printData();
    
    
}
void testbench::printData() {

   cout << "in " << intb.read()<<"\n";
   cout << "out " << outtb.read()<<"\n";


}
