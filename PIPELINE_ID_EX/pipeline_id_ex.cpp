#include "pipeline_id_ex.h"

pipeline_id_ex::pipeline_id_ex(sc_module_name nm) : 
  sc_module(nm), 
  inst1("inst1"),inst2("inst2"), inst3("inst3"), inst4("inst4"), 
  branch("branch"), memread("memread"), memtoreg("memtoreg"), aluop1("aluop1"), aluop2("aluop2"), aluop3("aluop3"), memwrite("memwrite"), alusrc("alusrc"), 
  readdata1("readdata1"), readdata2("readdata2"),
  immgen("immgen"), adder4("adder4"),
  inst1alu("inst1alu"),  
  inst2alu("inst2alu"), inst3alu("inst3alu"), inst4alu("inst4alu"),
  
  bp("bp"), mrp("mrp"), mtrp("mtrp"), alu1("alu1"), alu2("alu2"), alu3("alu3"), mwp("mwp"), as("as"), rd1("rd1"), rd2("rd2"), ig("ig"), igmux("igmux"), rd2mux("rd2mux"),
  adder4Out("adder4Out")
   {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  
  sensitive << inst1 << inst2 << inst3 << inst4 << branch << memread << memtoreg << aluop1 << aluop2 << aluop3 << memwrite << alusrc << readdata1 << readdata2 << immgen; // estas son las que van a cambiar
  dont_initialize();
   
}

void pipeline_id_ex::operation() { //  variableout.write(dato in);
    
    inst1alu.write(inst1.read());
    inst2alu.write(inst2.read());
    inst3alu.write(inst3.read());
    inst4alu.write(inst4.read());
    rd1.write(readdata1.read());
    rd2.write(readdata2.read());
    ig.write(immgen.read());
    bp.write(branch.read());
    mrp.write(memread.read());
    mtrp.write(memtoreg.read());
    alu1.write(aluop1.read());
    alu2.write(aluop2.read());
    alu3.write(aluop3.read());
    mwp.write(memwrite.read());
    as.write(alusrc.read());
    igmux.write(immgen.read());
    rd2mux.write(readdata2.read());  
    adder4Out.write(adder4.read());
  cout << "IDEX immGen "<< immgen.read() << endl;

    
}



 