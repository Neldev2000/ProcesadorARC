#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <systemc.h>

class testbench : public sc_module {
  public:
    /**
     * Como todo testbench, deberá recibir como entrada: el reloj y
     * los datos de salida del módulo a probar.
     * Y la salida será los datos de entrada del módulo a probar.
    */
	  sc_in<bool> clkIn;
      sc_in<sc_bv<32>> inInstruction, inAdd4, inAddBranch;
      sc_out<sc_bv<32>> oneli,ojump;
      sc_out<bool> om;

  	SC_CTOR(testbench);

  private:
	  void print();
	  void test();
    sc_bv<32> datoaim;
};

#endif // TESTBENCH_H_
