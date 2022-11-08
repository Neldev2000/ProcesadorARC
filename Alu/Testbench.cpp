#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
   // dont_initialize();
}
//@@@@@@ Metodo que Imprime las Salidas y Entradas
void Testbench::print() {
    std::cout << "RESUTADO: " << resIn.read()<<"   ENTERO: " <<resIn.read().to_int()<< "  ";
    std::cout << "   ZERO: " << zeroIn.read();
}

//@@@@@@ Metodo que hace las pruebas
void Testbench::test() {
    
    rs1Out.write("0010");
    rs2Out.write("0010");
    aluOpOut1.write(false);
    aluOpOut2.write(false);
    aluOpOut3.write(false);
    wait();
    print();
    rs1Out.write("0011");
    rs2Out.write("1010");
    aluOpOut1.write(true);
    aluOpOut2.write(true);
    aluOpOut3.write(true);
    wait();
    print();

    sc_stop();

}