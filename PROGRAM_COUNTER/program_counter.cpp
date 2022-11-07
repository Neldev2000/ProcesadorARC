#include "program_counter.h"

program_counter::program_counter(sc_module_name nm) : 
  sc_module(nm), 
  inputCounter("inputCounter"), 
  outInstruction("outInstruction"), outAdd4("outAdd4"), outAddBranch("outAddBranch") {//inicializar puertos

  SC_METHOD(operation);
  sensitive << inputCounter;
  dont_initialize();

}

void program_counter::operation() { //  variableout.write(dato in);
  outInstruction.write(inputCounter.read());
  outAdd4.write(inputCounter.read());
  outAddBranch.write(inputCounter.read());
}

