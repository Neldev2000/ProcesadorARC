#include "Mux4.h"

Mux4::Mux4(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << inneli << injump << im;                                               
  dont_initialize();
}

void Mux4::operation() {

  outmux.write( ( im.read()==1? injump.read() : inneli.read() ) );

}

Mux4::~Mux4() {}
