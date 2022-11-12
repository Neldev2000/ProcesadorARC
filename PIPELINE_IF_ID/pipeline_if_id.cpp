#include "pipeline_if_id.h"

pipeline_if_id::pipeline_if_id(sc_module_name nm) : 
  sc_module(nm), 
  i30("i30"), i14("i14"), i13("i13"), i12("i12"), 
  i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),

  iminrd("iminrd"), iminrs2("iminrs2"), iminrs1("iminrs1"), 
  imingen("imingen"), adder4("adder4"), 

  i30Out("i30Out"), i14Out("i14Out"), i13Out("i13Out"), i12Out("i12Out"),
  i6Out("i6Out"), i5Out("i5Out"), i4Out("i4Out"), i3Out("i3Out"), i2Out("i2Out"),
  imoutrd("imOutrd"), imoutrs2("imOutrs2"), imoutrs1("imOutrs1"), 
  imoutgen("imOutgen"), adder4Out("adder4Out") {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << i30    << i14     << i13 << i12
            << i6     << i5      << i4  << i3  << i2
            << iminrd << iminrs2 << iminrs1 
            << imingen; // estas son las que van a cambiar
  dont_initialize();
   
}

void pipeline_if_id::operation() { //  variableout.write(dato in);

  cout << "i30: " << i30.read() << endl
       << "i14: " << i14.read() << endl
       << "i13: " << i13.read() << endl
       << "i12: " << i12.read() << endl
       << "rd: " << iminrd.read() << endl
       << "rs1: " << iminrs1.read() << endl
       << "immGen: " << imingen.read() << endl;


  i30Out.write(i30.read());
  i14Out.write(i14.read());
  i13Out.write(i13.read());
  i12Out.write(i12.read());

  i6Out.write(i6.read());
  i5Out.write(i5.read());
  i4Out.write(i4.read());
  i3Out.write(i3.read());
  i2Out.write(i2.read());


  imoutrs1.write(iminrs1.read());
  imoutrs2.write(iminrs2.read());
  imoutrd.write(iminrd.read());
  imoutgen.write(imingen.read());
  adder4Out.write(adder4.read());
}



 