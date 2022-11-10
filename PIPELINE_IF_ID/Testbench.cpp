#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test); // selecciono funcion de arranque
  sensitive << clkIn.pos(); //pos cuando se;al es 1
  //dont_initialize();
}

void Testbench::print() {
 cout << "\nsi sirve\n";
 cout << "out Alu Control: " << in1 << "\n";
 cout << "out gen:" << in2 << "\n";
 cout << "out rd:" << in3 << "\n";
 cout << "out rs2:" << in4 << "\n";
 cout << "out rs1:" << in5 << "\n";
 cout << "out control:" << in6 << "\n";
 cout << "out add branch:" << in7 << "\n";



}

void Testbench::test() {

out1.write("0000"); // de 0 a 31
out2.write("010010100010"); // de 0 a 31
out3.write("00110"); // de 0 a 31
out4.write("01011");
out5.write("10100");
out6.write("0100100");
out7.write("00000000100110101010010110110110");

wait(); // genero entradas espero e imprimo, es paralelizado, si no espero se ejcuta simultaneamente la impresion y asignacion
wait(); 

print(); //llamo a resto de funciones

sc_stop();
}
