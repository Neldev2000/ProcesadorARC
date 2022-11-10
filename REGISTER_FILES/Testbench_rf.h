#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class Testbench : public sc_module {
  public:
    /**
     * Como todo testbench, deberá recibir como entrada: el reloj y
     * los datos de salida del módulo a probar.
     * Y la salida será los datos de entrada del módulo a probar.
    */
	  sc_in<bool> clkIn;
      sc_in<sc_bv<32>> ind1, ind2;
	  sc_out<sc_bv<5>> outs1, outs2, outs3;
      sc_out<sc_bv<32>> outs4;
       sc_out<bool> testuc;
    

  	SC_CTOR(Testbench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H_
