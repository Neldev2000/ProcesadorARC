#ifndef MUX_4_H_
#define MUX_4_H_

#include <systemc.h>

class Mux4: public sc_module {
  public:
    sc_in<bool> im;
    sc_in<sc_bv<32>> inneli, injump;
    sc_out<sc_bv<32>> outmux;
    
    SC_CTOR(Mux4);
    ~Mux4();

  private:
    void operation();
};

#endif
