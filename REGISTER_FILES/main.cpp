#include "register_files.h"  
#include "Testbench_rf.h"

int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  register_files registerfiles("reg_fil");
  Testbench tb("testBench");

  // Necesitaremos cables para conectar los módulos
  sc_signal<sc_bv<5>> ct4, ct2, ct3;
  sc_signal<sc_bv<32>> ct1, cq1, cq2;
  sc_signal<bool> cq3;
  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables

  registerfiles.rs1(ct4);
  registerfiles.rs2(ct3);
  registerfiles.rd(ct2);
  registerfiles.wd(ct1);
  registerfiles.rs1d(cq1);
  registerfiles.rs2d(cq2);
  registerfiles.regwritein(cq3);
  
  tb.ind1(cq1);
  tb.ind2(cq2);
  tb.outs1(ct4);
  tb.outs2(ct3);
  tb.outs3(ct2);
  tb.outs4(ct1);
  // Conectando el reloj al testbench
  tb.clkIn(clock);
  tb.testuc(cq3);

  // Inicializando el simulador
  sc_start();

  return 0;
}