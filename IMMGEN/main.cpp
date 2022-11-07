#include "immgen.h"  
#include "testbench.h"


int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  immgen immgen("immgen");
  testbench tb("testbench");
  
  // Necesitaremos cables para conectar los módulos

  sc_signal<sc_bv<32>> cextb;
  sc_signal<sc_bv<12>> ctbex;
  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables

  immgen.inex(ctbex);
  immgen.outex(cextb);

  tb.intb(cextb);
  tb.outtb(ctbex);
  
  // Conectando el reloj al testbench
  tb.clock(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}