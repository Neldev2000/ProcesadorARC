#include "Testbench_rf.h"
#include <iostream>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test); // selecciono funcion de arranque
  sensitive << clkIn.pos(); //pos cuando se;al es 1
  //dont_initialize();
}

void Testbench::print() {
  std::cout << sc_time_stamp() << "    "; //tiempo

  std::cout << ind1.read() << "    ";
  std::cout << ind2.read() << "    ";


  std::cout << outs1.read() << "    ";
  std::cout << outs2.read() << "    ";
  std::cout << outs3.read() << "    ";
  std::cout << outs4.read() << "    ";

}

void Testbench::test() {

outs1.write("00001");
outs2.write("00001");
outs3.write("00001");
outs4.write("01");
wait(); // genero entradas espero e imprimo, es paralelizado, si no espero se ejcuta simultaneamente la impresion y asignacion
 std::cout << ind2.read() << "    ";
/*
std::cout << "rs1 rs2 rd wd rs1d rs2d";

  std::cout << rs1.read() << "    ";
  std::cout << rs2.read() << "    ";
  std::cout << rd.read() << "    ";
  std::cout << wd.read() << "    ";
  std::cout << rs1d.read() << "    ";
  std::cout << rs2d.read() << "    ";

*/

   // print(); //llamo a resto de funciones

  sc_stop();
}
