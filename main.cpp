#include "utils.h"
//#include "instructionMemory.h"
int sc_main(int argc, char *argv[])
{
    // IF-ID
    
    pipeline_if_id pipelineIfId("pipelineIfId");
    InstructionMemory instructionMemory("instructionMemory");

    //Conectar Instruction Memory con Pipeline

    sc_signal<bool> channelI30, channelI14, channelI13, channelI12;
    sc_signal<bool> channelI6, channelI5, channelI4, channelI3, channelI2;
    sc_signal<sc_bv<5>> channelRs1, channelRs2, channelRd;
    sc_signal<sc_bv<12>> channelImmGen;

    instructionMemory.i30(channelI30);
    pipelineIfId.i30(channelI30);

    instructionMemory.i14(channelI14);
    pipelineIfId.i14(channelI14);
    
    instructionMemory.i13(channelI13);
    pipelineIfId.i13(channelI13);

    instructionMemory.i12(channelI12);
    pipelineIfId.i12(channelI12);

/// --------------------------------------------

    instructionMemory.i6(channelI6);
    pipelineIfId.i6(channelI6);

    instructionMemory.i5(channelI5);
    pipelineIfId.i5(channelI5);

    instructionMemory.i4(channelI4);
    pipelineIfId.i4(channelI4);

    instructionMemory.i3(channelI3);
    pipelineIfId.i3(channelI3);

    instructionMemory.i2(channelI2);
    pipelineIfId.i2(channelI2);

/// --------------------------------------------
    instructionMemory.rs1(channelRs1);
    pipelineIfId.iminrs1(channelRs1);
    
    instructionMemory.rs2(channelRs2);
    pipelineIfId.iminrs2(channelRs2);

    instructionMemory.rd(channelRd);
    pipelineIfId.iminrd(channelRd);

/// --------------------------------------------

    instructionMemory.immGen(channelImmGen);
    pipelineIfId.imingen(channelImmGen);

/// --------------------------------------------
/// --------------------------------------------
/// --------------------------------------------

    program_counter programCounter("programCounter");
    Adder4 adder4("Adder4");

    sc_signal<sc_bv<32>> channelPCtoinstructionMemory, channelPCtoAdder4, channelAdder4toMux;
    
    programCounter.outInstruction(channelPCtoinstructionMemory);
    instructionMemory.programCounterIndex(channelPCtoinstructionMemory);

    programCounter.outAdd4(channelPCtoAdder4);
    adder4.pcIn(channelPCtoAdder4);

    //TODO: Conectar adder4.pcOut con mux
    //TODO: Conectar mux.Out con programCounter.    

    // IF-ID


    // if/id - id/ex


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
 
  ControlUnit controlUnit("controlUnit");
  register_files registerfiles("reg_fil");
  IMMGEN immgen("immgen");
  pipeline_id_ex pipeline_id_ex("pipe_idex");


  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> it1, it2, it3, it4, cib2, cib3, cib4, cib5, cib6, cdregister, cmw, cmtr, cmr, cb, cas, cao2, cao1, cao0;
  sc_signal<sc_bv<5>> crs1, crs2, crd ;
  sc_signal<sc_bv<12>> cgenin;
  sc_signal<sc_bv<32>> crd1, crd2, coutgen;

  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables modulo.

 //pipelineIfId pipelineIfId.puerto(cable);

   pipelineIfId.i12Out(it1);
   pipelineIfId.i13Out(it2);
   pipelineIfId.i14Out(it3);
   pipelineIfId.i30Out(it4);

   pipelineIfId.i2Out(cib2);
   pipelineIfId.i3Out(cib3);
   pipelineIfId.i4Out(cib4);
   pipelineIfId.i5Out(cib5); 
   pipelineIfId.i6Out(cib6);  

   pipelineIfId.imoutrs1(crs1);
   pipelineIfId.imoutrs2(crs2);
   pipelineIfId.imoutrd(crd);

   pipelineIfId.imoutgen(cgenin); 


   // controlUnit.puerto(cable);

   controlUnit.i2(cib2);
   controlUnit.i3(cib3);
   controlUnit.i4(cib4);
   controlUnit.i5(cib5);
   controlUnit.i6(cib6);

   controlUnit.regWrite(cdregister);
   controlUnit.memWrite(cmw);
   controlUnit.memToReg(cmtr);
   controlUnit.memRead(cmr);
   controlUnit.branch(cb);
   controlUnit.aluSrc(cas);
   controlUnit.aluOp2(cao2);
   controlUnit.aluOp1(cao1);
   controlUnit.aluOp0(cao0);

   //registerfiles.puerto(cable);

   registerfiles.rs1(crs1);
   registerfiles.rs2(crs2);
   registerfiles.rd(crd);

   registerfiles.rs1d(crd1);
   registerfiles.rs2d(crd2);
   //definir entrada wd

   registerfiles.regwritein(cdregister);

  //immgen.puerto(cable);

   immgen.inex(cgenin);
   immgen.outex(coutgen);
   // definir salida outbranch1

 // pipeline_id_ex.puerto(cable);

   pipeline_id_ex.inst1(it1);
   pipeline_id_ex.inst2(it2);
   pipeline_id_ex.inst3(it3);
   pipeline_id_ex.inst4(it4);

   pipeline_id_ex.readdata1(crd1);
   pipeline_id_ex.readdata2(crd2);

   pipeline_id_ex.memwrite(cmw);
   pipeline_id_ex.memtoreg(cmtr);
   pipeline_id_ex.memread(cmr);
   pipeline_id_ex.branch(cb);
   pipeline_id_ex.alusrc(cas);
   pipeline_id_ex.aluop2(cao2);
   pipeline_id_ex.aluop1(cao1);
   pipeline_id_ex.aluop3(cao0);

   pipeline_id_ex.immgen(coutgen);
  // Conectando el reloj al testbench

    sc_start();
    return 0;
}