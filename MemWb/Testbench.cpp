
#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
   // dont_initialize();
}
//@@@@@@ Metodo que Imprime la Salida
void Testbench::print() {
    std::cout << "ReadData: " << rdMuxIn.read()<<"\nRes: " << 
        rMuxIn.read()<< "\nMemToReg: " << mtrMuxIn.read();
}

//@@@@@@ Metodo que hace las pruebas
void Testbench::test() {
	rOut.write("0101");
    rdOut.write("10111");
	mtrOut.write(false);


    wait();
    print();
    sc_stop();

}