
#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
   // dont_initialize();
}
//@@@@@@ Metodo que Imprime la Salida
void Testbench::print() {
    std::cout << "RESUTADO: " << readDataIn.read()<<"--ENTERO: " << readDataIn.read().to_int()<< "  ";
}

//@@@@@@ Metodo que hace las pruebas
void Testbench::test() {
	addressOut.write("01");
    writeDataOut.write("111");
	memWriteOut.write(true);
    memReadOut.write(false);



    wait();
    print();
    sc_stop();

}