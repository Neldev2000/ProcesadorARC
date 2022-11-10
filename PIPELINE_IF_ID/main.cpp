#include "Testbench.h"
#include "pipeline_if_id.h" 

int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  pipeline_if_id pipeline_if_id("pipe_ifid");
  Testbench tb("testBench");

  // Necesitaremos cables para conectar los módulos
  sc_signal<sc_bv<4>> c1d, c1i;
  sc_signal<sc_bv<5>> c5d, c5i, c4d, c4i, c3d, c3i;
  sc_signal<sc_bv<7>> c6d, c6i;
  sc_signal<sc_bv<12>> c2d, c2i;
  sc_signal<sc_bv<32>> c7d, c7i;
  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables

  pipeline_if_id.inaddbranch(c7i);
  pipeline_if_id.imincontrol(c6i);
  pipeline_if_id.iminrs1(c5i);
  pipeline_if_id.iminrs2(c4i);
  pipeline_if_id.iminrd(c3i);
  pipeline_if_id.imingen(c2i);
  pipeline_if_id.iminalucontrol(c1i);

  pipeline_if_id.outaddbranch(c7d);
  pipeline_if_id.imoutcontrol(c6d);
  pipeline_if_id.imoutrs1(c5d);
  pipeline_if_id.imoutrs2(c4d);
  pipeline_if_id.imoutrd(c3d);
  pipeline_if_id.imoutgen(c2d);
  pipeline_if_id.imoutalucontrol(c1d);
  

  tb.in1(c1d);
  tb.in2(c2d);
  tb.in3(c3d);
  tb.in4(c4d);
  tb.in5(c5d);
  tb.in6(c6d);
  tb.in7(c7d);

  tb.out1(c1i);
  tb.out2(c2i);
  tb.out3(c3i);
  tb.out4(c4i);
  tb.out5(c5i);
  tb.out6(c6i);
  tb.out7(c7i);

  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}