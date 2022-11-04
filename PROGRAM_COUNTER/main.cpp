#include "program_counter.h"  
#include "testbench_pc.h"
#include "Mux4.h"

int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  program_counter program_counter("pro_cou");
  testbench tb("testbench");
  Mux4 mux4("mux4");

  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> cm;
  sc_signal<sc_bv<32>> cmuxpc, cpctb1, cpctb2,cneli,cjump;
  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables

  mux4.inneli(cneli);
  mux4.injump(cjump);
  mux4.im(cm);
  mux4.outmux(cmuxpc);

  program_counter.inpc(cmuxpc);
  program_counter.outpc(cpctb1);
  program_counter.outpc(cpctb2);
  
  tb.inadd(cpctb1);
  tb.inim(cpctb2);
  tb.oneli(cneli);
  tb.ojump(cjump);
  tb.om(cm);
  
  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}