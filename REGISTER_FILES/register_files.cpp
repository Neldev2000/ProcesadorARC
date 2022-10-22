#include "register_files.h"

Register_Files::Register_Files(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << rs1 << rs2 << rd << wd; // estas son las que van a cambiar
  dont_initialize();
}

void Register_Files::operation() { //  variableout.write(dato in);

  rs1d.write(register_list[rs1.read()]);
  rs2d.write(register_list[rs2.read()]);
  register_list[rd.read()]=wd.read();
}

Register_Files::~Register_Files() {}


