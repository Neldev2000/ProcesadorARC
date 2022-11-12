#include "program_counter.h"

program_counter::program_counter(sc_module_name nm) : 
  sc_module(nm), 
  inputCounter("inputCounter"), 

  outInstruction("outInstruction"), outAdd4("outAdd4"), flag(false) {//inicializar puertos
  SC_METHOD(operation);
  sensitive  << inputCounter;
  //dont_initialize();
  

}

void program_counter::operation() { //  variableout.write(dato in);
  cout << "PC: \n";
  if(flag == true){
  outInstruction.write(inputCounter.read());
  outAdd4.write(inputCounter.read());
  }else{
    outInstruction.write("1");
    outAdd4.write("1");
    flag = true;
  }

  cout << "Instruction: " << outInstruction.read() << "\n"
      << "Adder4: " << outAdd4.read() << '\n';

}

