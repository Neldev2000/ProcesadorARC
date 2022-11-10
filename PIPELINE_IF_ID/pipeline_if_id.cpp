#include "pipeline_if_id.h"

pipeline_if_id::pipeline_if_id(sc_module_name nm) : sc_module(nm), iminalucontrol("iminalucontrol"), iminrd("iminrd"), iminrs2("iminrs2"), iminrs1("iminrs1"), imincontrol("imincontrol"), imingen("imingen"), inaddbranch("inaddbranch"), imoutcontrol("imincontrol"), imoutrd("iminrd"), imoutrs2("iminrs2"), imoutrs1("iminrs1"), imoutalucontrol("iminalucontrol"), imoutgen("imingen"), outaddbranch("inaddbranch") {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << inaddbranch << imincontrol << iminrs1 << iminrs2 << iminrd << imingen << iminalucontrol; // estas son las que van a cambiar
  dont_initialize();
   
}

void pipeline_if_id::operation() { //  variableout.write(dato in);

    outaddbranch.write(inaddbranch.read());
    imoutcontrol.write(imincontrol.read());
    imoutrs1.write(iminrs1.read());
    imoutrs2.write(iminrs2.read());
    imoutrd.write(iminrd.read());
    imoutgen.write(imingen.read());
    imoutalucontrol.write(iminalucontrol.read());

}



 