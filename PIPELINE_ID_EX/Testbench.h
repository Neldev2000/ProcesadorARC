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

    sc_in<bool> inst1in, inst2in, inst3in, inst4in, bin, mrin, mtrin, a1in, a2in, a3in, mwin, asrcin; 
    sc_in<sc_bv<32>> rd1in, rd2in, igin;

    sc_out<bool> inst1out,  inst2out, inst3out, inst4out, bout, mrout, mtrout, a1out, a2out, a3out, mwout, asrcout;
    sc_out<sc_bv<32>> rd1out, rd2out, igout;


  	SC_CTOR(Testbench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H_
