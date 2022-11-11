#include "Testbench.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test); // selecciono funcion de arranque
  sensitive << clkIn.pos(); //pos cuando se;al es 1
  //dont_initialize();
}

void Testbench::print() {
 cout << "\nsi sirve\n";
 cout << "inst 1 Alu: " << inst1in << "\n"; // falta esto
 cout << "inst 2 Alu: " << inst2in << "\n";
 cout << "inst 3 Alu: " << inst3in << "\n";
 cout << "inst 4 Alu: " << inst4in << "\n";
 cout << "rd1: " << rd1in << "\n";
 cout << "rd2: " << rd2in << "\n";
 cout << "ig: " << igin << "\n";
 cout << "bp: " << bin << "\n";
 cout << "mrp: " << mrin << "\n";
 cout << "mtrp: " << mtrin << "\n";
 cout << "alu1: " << a1in << "\n";
 cout << "alu2: " << a2in << "\n";
 cout << "alu3: " << a3in << "\n";
 cout << "mwp: " << mwin << "\n";
 cout << "as: " << asrcin << "\n";

}

void Testbench::test() {

inst1out.write(0); // bool
inst2out.write(0); // bool
inst3out.write(0); // bool
inst4out.write(0); // bool
rd1out.write("00000000100110101010010110110110"); //32
rd2out.write("00000000100110101010010110110110"); //32
igout.write("00000000100110101010010110110110"); //32
bout.write(0); // bool
mrout.write(0); // bool
mtrout.write(0); // bool
a1out.write(0); // bool
a2out.write(0); // bool
a3out.write(0); // bool
mwout.write(0); // bool
asrcout.write(0); // bool

wait(); // genero entradas espero e imprimo, es paralelizado, si no espero se ejcuta simultaneamente la impresion y asignacion
wait(); 

print(); //llamo a resto de funciones

sc_stop();
}
