#include "testbench_pc.h"
#include <iostream>

testbench::testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test); // selecciono funcion de arranque
  sensitive << clkIn.pos(); //pos cuando se;al es 1
  //dont_initialize();
}

void testbench::print() {

  std::cout << inadd.read()<< " lo que entra       "; 

  std::cout << oneli.read()<< " out_if_next_line   "; 

  std::cout << ojump.read() << " out_if_jump        ";

  std::cout << om.read() << " out_mux_choice     ";
  
}

void testbench::test() {

  //datoaim.write(inim.read());

oneli.write("100");
ojump.write("11100");
om.write("1");
wait();

 // genero entradas espero e imprimo, es paralelizado, si no espero se ejcuta simultaneamente la impresion y asignacion
 //std::cout << ind2.read() << "    ";
/*
std::cout << "rs1 rs2 rd wd rs1d rs2d";

  std::cout << rs1.read() << "    ";
  std::cout << rs2.read() << "    ";
  std::cout << rd.read() << "    ";
  std::cout << wd.read() << "    ";
  std::cout << rs1d.read() << "    ";
  std::cout << rs2d.read() << "    ";

*/

   print(); //llamo a resto de funciones

  sc_stop();
}
