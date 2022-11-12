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


    Adder4 adder4("adder4");
    sc_signal<sc_bv<32>> channAddToIFID;
    adder4.pcOut(channAddToIFID);
    pipelineIfId.adder4(channAddToIFID);



    program_counter programCounter("programCounter");
    sc_signal<sc_bv<32>> channPCADD, channPCInst;
    adder4.pcIn(channPCADD);
    programCounter.outAdd4(channPCADD);

    instructionMemory.programCounterIndex(channPCInst);
    programCounter.outInstruction(channPCInst);

/// --------------------------------------------
/// --------------------------------------------
/// --------------------------------------------
    //TODO: Conectar adder4.pcOut con mux
    //TODO: Conectar mux.Out con programCounter.    

    // IF-ID

    
    // if/id - id/ex


  // Creando instancias de los módulos
 
 
  
  

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
    ControlUnit controlUnit("controlUnit");
 
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
     register_files registerfiles("reg_fil");
   registerfiles.rs1(crs1);
   registerfiles.rs2(crs2);
   registerfiles.rd(crd);

   registerfiles.rs1d(crd1);
   registerfiles.rs2d(crd2);
   //definir entrada wd

   registerfiles.regwritein(cdregister);

  //immgen.puerto(cable);
    IMMGEN immgen("immgen");
   immgen.inex(cgenin);
   immgen.outex(coutgen);
   // definir salida outbranch1

 // pipeline_id_ex.puerto(cable);

    pipeline_id_ex pipeline_id_ex("pipe_idex");


    sc_signal<sc_bv<32>> channAdderIF_EX;
    pipelineIfId.adder4Out(channAdderIF_EX);
    pipeline_id_ex.adder4(channAdderIF_EX);


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

  // EX - MEM
  
  //@@@@@@@@@Reloj

    DataMemory datamemory("datamemory");
    MemWb memwb("memwb");
	ExMem exmem("exmen");
	AndGate andGate("and");
	Alu alu("alu");
	ALUControl alucontrol("alucontrol");
	//pipeline_id_ex pipeline_id_ex("pipeline_id_ex");
/// ---------------------------

    sc_signal<sc_bv<32>> channelADDEX_MEM, channelADDMEM_WB;
    
    pipeline_id_ex.adder4Out(channelADDEX_MEM);
    exmem.adder4(channelADDEX_MEM);

    exmem.adder4Out(channelADDMEM_WB);
    memwb.adder4(channelADDMEM_WB);


    sc_signal<sc_bv<32>> channelIMMGEN_WB;
    exmem.sumMux(channelIMMGEN_WB);
    memwb.immGenBranch(channelIMMGEN_WB);

/// ---------------------------
    sc_signal<sc_bv<32>> readDataSg,rSg,aSg, mdSg,resSg,rd1Sg,rd2Sg,wdSg,igSg;
	sc_signal<bool> mwDmSg,mrDmSg,and1Sg, and2Sg,zeroSg,alu1Sg,alu2Sg,alu3Sg,bpSg,mtrp2Sg,mtrpSg,mwpSg,i1Sg,i2Sg,i3Sg,i4Sg,op1Sg,op2Sg,op3Sg,mrpSg;

    //@@@@@@@@@Conexion con los Canales correspondientes



	//@@@@Conexion de Data Memory a Pipeline Mem/Wb
	datamemory.readData(readDataSg);
	memwb.readData(readDataSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal MemToReg a Pipeline Mem/Wb
	exmem.memToRegP(mtrp2Sg);
	memwb.memToReg(mtrp2Sg);

	//@@@@Conexion de Pipeline Ex/Mem Señal Res(Alu) a Pipeline Mem/Wb
	exmem.rp(rSg);
	memwb.res(rSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal MemWrite a Data Memory
	exmem.memWriteDm(mwDmSg);
	datamemory.memWrite(mwDmSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal Res(Alu) a Data Memory
	exmem.addressDm(aSg);
	datamemory.address(aSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal WriteData a Data Memory
	exmem.writeDataDm(wdSg);
	datamemory.writeData(wdSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal MemRead a Data Memory
	exmem.memReadDm(mrDmSg);
	datamemory.memRead(mrDmSg);

	//@@@@Conexion de Pipeline Ex/Mem Señal Brach a And Gate
	exmem.brachAnd(and1Sg);
	andGate.inA(and1Sg);

	//@@@@Conexion de Pipeline Ex/Mem Señal Zero(Alu) a And Gate
	exmem.zeroAnd(and2Sg);
	andGate.inB(and2Sg);

    sc_signal<bool>channAND_WB;
    andGate.output(channAND_WB);
    memwb.andGate(channAND_WB);

	//@@@@Conexion de ALU Señal Zero(Alu) a Pipeline Ex/Mem
	

	//@@@@Conexion de ALU Control Señal ALUop1 a ALU
	alucontrol.aluF0(alu1Sg);
	alu.aluOp1(alu1Sg);

	//@@@@Conexion de ALU Control Señal ALUop2 a ALU
	alucontrol.aluF1(alu2Sg);
	alu.aluOp2(alu2Sg);

	//@@@@Conexion de ALU Control Señal ALUop3 a ALU
	alucontrol.aluF2(alu3Sg);
	alu.aluOp3(alu3Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal rs1 a ALU
	pipeline_id_ex.rd1(rd1Sg);
	alu.rs1(rd1Sg);

    //Conexion Pipeline
    Mux2a1 muxALU("muxALU");
    sc_signal<sc_bv<32>> channImmGenToMux, channelrd2ToMux, channRs2ALU;
    sc_signal<bool> channAluSrc;

    muxALU.inA(channImmGenToMux);
    pipeline_id_ex.igmux(channImmGenToMux);

    muxALU.inB(channelrd2ToMux);
    pipeline_id_ex.rd2mux(channelrd2ToMux);

    muxALU.controlSignal(channAluSrc);
    pipeline_id_ex.as(channAluSrc);

    muxALU.output(channRs2ALU);
    alu.rs2(channRs2ALU);

    alu.zero(zeroSg);
	exmem.zero(zeroSg);

	//@@@@Conexion de ALU Señal Res(Resultado) a Pipeline Ex/Mem
	alu.res(resSg);
	exmem.res(resSg);

	//@@@@Conexion de Pipeline Id/Ex Señal branch a Ex/Mem
	pipeline_id_ex.bp(bpSg);
	exmem.brach(bpSg);

	//@@@@Conexion de Pipeline Id/Ex Señal Imm Gen a Ex/Mem
	pipeline_id_ex.ig(igSg);
	exmem.sum(igSg);

	//@@@@Conexion de Pipeline Id/Ex Señal Mem To Reg a Ex/Mem
	pipeline_id_ex.mtrp(mtrpSg);
	exmem.memToReg(mtrpSg);

	//@@@@Conexion de Pipeline Id/Ex Señal MemWrite a Ex/Mem
	pipeline_id_ex.mwp(mwpSg);
	exmem.memWrite(mwpSg);

	//@@@@Conexion de Pipeline Id/Ex Señal Read Data 2 a Ex/Mem
	pipeline_id_ex.rd2(rd2Sg);
	exmem.readData2(rd2Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal MemRead a Ex/Mem
	pipeline_id_ex.mrp(mrpSg);
	exmem.memRead(mrpSg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu inst 1 a ALU Control
	pipeline_id_ex.inst1alu(i1Sg);
	alucontrol.i12(i1Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu inst 2 a ALU Control
	pipeline_id_ex.inst2alu(i2Sg);
	alucontrol.i13(i2Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu inst 3 a ALU Control
	pipeline_id_ex.inst3alu(i3Sg);
	alucontrol.i14(i3Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu inst 4 a ALU Control
	pipeline_id_ex.inst4alu(i4Sg);
	alucontrol.i30(i4Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu Op 1 a ALU Control
	pipeline_id_ex.alu1(op1Sg);
	alucontrol.aluOp0(op1Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu Op 2 a ALU Control
	pipeline_id_ex.alu2(op2Sg);
	alucontrol.aluOp1(op2Sg);

	//@@@@Conexion de Pipeline Id/Ex Señal Alu Op 3 a ALU Control
	pipeline_id_ex.alu3(op3Sg);
	alucontrol.aluOp2(op3Sg);
  


  // EX - MEM
  

    Mux2a1 muxPC("muxPC");
    sc_signal<sc_bv<32>> channAdder4, channBranch, channNewPC;
    sc_signal<bool> channAndGate;

    muxPC.inA(channBranch);
    memwb.immGenBranchOut(channBranch);

    muxPC.inB(channAdder4);
    memwb.adder4Out(channAdder4);

    muxPC.controlSignal(channAndGate);
    memwb.andGateOut(channAndGate);

    muxPC.output(channNewPC);
    programCounter.inputCounter(channNewPC);

    Mux2a1 muxWriteData("muxWriteData");
    sc_signal<sc_bv<32>> channReadData, channRes, channWriteData;
    sc_signal<bool> channMemToReg;

    muxWriteData.inA(channReadData);
    memwb.readDataMux(channReadData);

    muxWriteData.inB(channRes);
    memwb.resMux(channRes);

    muxWriteData.controlSignal(channMemToReg);
    memwb.memToRegMux(channMemToReg);

    muxWriteData.output(channWriteData);
    registerfiles.wd(channWriteData);

    sc_start();
    return 0;
}
