#include "register_files.h"

register_files::register_files(sc_module_name nm) : sc_module(nm), rs1("rs1"), rs2("rs2"), rd("rd"), wd("wd"), rs1d("rs1d"), rs2d("rs2d"), register_list(32) {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << rs1 << rs2 << rd << wd; // estas son las que van a cambiar
  dont_initialize();
  register_list[1] = "1001";
}

void register_files::operation() { //  variableout.write(dato in);

  cout << "rs1: " << register_list[1]  << endl;
  rs2d.write(register_list[1] );
  /*rs1d.write(register_list[rs1.read().to_int()]);
  rs2d.write(register_list[rs2.read().to_int()]);
  register_list[rd.read().to_int()]=wd.read();*/
}


