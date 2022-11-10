#include "Testbench_rf.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test); // selecciono funcion de arranque
  sensitive << clkIn.pos(); //pos cuando se;al es 1
  //dont_initialize();
}

void Testbench::print() {
  cout << "rs1d" << ind1 << "\n";
    cout << "rs2d" << ind2 << "\n";

}

void Testbench::test() {

outs1.write("00000"); // de 0 a 31
outs2.write("00001"); // de 0 a 31
outs3.write("00110"); // de 0 a 31
outs4.write("11100111");
testuc.write(1);

wait(); // genero entradas espero e imprimo, es paralelizado, si no espero se ejcuta simultaneamente la impresion y asignacion
wait(); 

print(); //llamo a resto de funciones

sc_stop();
}
