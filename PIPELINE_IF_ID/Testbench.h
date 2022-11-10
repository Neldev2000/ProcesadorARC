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

    sc_in<sc_bv<4>> in1;
    sc_in<sc_bv<5>> in3, in4, in5;
    sc_in<sc_bv<7>> in6;
    sc_in<sc_bv<12>> in2;
    sc_in<sc_bv<32>> in7;

    sc_out<sc_bv<4>> out1;
    sc_out<sc_bv<5>> out3,out4,out5;
    sc_out<sc_bv<7>> out6;
    sc_out<sc_bv<12>> out2;
    sc_out<sc_bv<32>> out7;
    

  	SC_CTOR(Testbench);

  private:
	  void print();
	  void test();
};

#endif // TESTBENCH_H_
