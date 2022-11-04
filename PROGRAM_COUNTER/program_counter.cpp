#include "program_counter.h"

program_counter::program_counter(sc_module_name nm) : sc_module(nm), inpc("inpc"), outpc("outpc") {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << inpc; // estas son las que van a cambiar
  dont_initialize();
}

void program_counter::operation() { //  variableout.write(dato in);
outpc.write(inpc.read());

}

