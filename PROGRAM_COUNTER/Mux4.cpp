#include "Mux4.h"

Mux4::Mux4(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << inneli << injump << im;                                               
  dont_initialize();
}

void Mux4::operation() {

  if (im==0) {
    outmux.write(inneli.read());
  }

  if (im==1) {
    outmux.write(injump.read());
  }

}

Mux4::~Mux4() {}
