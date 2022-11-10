
#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
    SC_THREAD(test);
    sensitive << clkIn.pos();
   // dont_initialize();
}
//@@@@@@ Metodo que Imprime la Salida
void Testbench::print() {

    std::cout << "REGISTROS: \n";
    std::cout << "Sum: " << sMuxIn.read()<<"\nZero: " << zAndIn.read()<<
        "\nRes: " << aIn.read()<<"\nRead Data: " << wdIn.read();

    std::cout << "\nSEÑALES DE CONTROL: \n";
    std::cout << "Brach: " << bAndIn.read()<<"\nMemRead: " << mrDmIn.read()<<
        "\nMemWrite: " <<mwDmIn.read()<<"\nMemToReg: " << mtrPIn.read();
}

//@@@@@@ Metodo que hace las pruebas
void Testbench::test() {
	sumOut.write("11");
    zOut.write(true);
    resOut.write("1010");
    rd2Out.write("10111");
    bOut.write(false);
    mrOut.write(true);
    mwOut.write(false);
	mtrOut.write(true);

    wait();
    print();
    sc_stop();

}