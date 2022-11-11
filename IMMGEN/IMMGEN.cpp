#include "IMMGEN.h"
#include <iostream>
using namespace std;

IMMGEN::IMMGEN(sc_module_name nm) : sc_module(nm), inex("inex"), outex("outex") {//inicializar puertos

  SC_METHOD(process); // cuando las variables cambien ejecuta esa funcion
  sensitive << inex; // estas son las que van a cambiar
  dont_initialize();
}

void IMMGEN::process() {

sc_bv<1> s = inex.read().range(11,11);
cout<< "\n" << "s= "<< s.to_string()<< "\n"; //string convierte en cadena ver valor real
if (s.to_string()=="1"){
    sc_bv<20> sap;
    outex.write(("11111111111111111111"+inex.read().to_string()).c_str()); // convierte string a cadena de caracteres
    outbranch1.write(("11111111111111111111"+inex.read().to_string()).c_str());
}else{
    outex.write(inex.read());
     outbranch1.write(inex.read());
}


}
