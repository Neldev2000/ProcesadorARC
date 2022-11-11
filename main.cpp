// montando el main principal
//0 - if/id

int main() {















































































































































// if/id - id/ex


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  pipeline_id_ex pipeline_id_ex("pipe_idex");
  Testbench tb("testBench");

  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> i1sg, i2sg, i3sg, i4sg, bsg, mrsg, mtrsg, a3, a2, a1, mwsg, asrcsg;
  sc_signal<sc_bv<32>> readdata1sg, readdata2sg, immgensg;

  sc_signal<bool> inst1sg, inst2sg, inst3sg, inst4sg, bps, mrpsg, mtrpsg, alu1sg, alu2sg, alu3sg, mwpsg, assg;
  sc_signal<sc_bv<32>> rd1sg, rd2sg, igsg;

  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables

  pipeline_id_ex.inst1(i1sg);
  tb.inst1out(i1sg);

  pipeline_id_ex.inst2(i2sg);
  tb.inst2out(i2sg);

  pipeline_id_ex.inst3(i3sg);
  tb.inst3out(i3sg);

  pipeline_id_ex.inst4(i4sg);
  tb.inst4out(i4sg);

  pipeline_id_ex.readdata1(readdata1sg);
  tb.rd1out(readdata1sg);

  pipeline_id_ex.readdata2(readdata2sg);
  tb.rd2out(readdata2sg);

  pipeline_id_ex.immgen(immgensg);
  tb.igout(immgensg);

  pipeline_id_ex.branch(bsg);
  tb.bout(bsg);

  pipeline_id_ex.memread(mrsg);
  tb.mrout(mrsg);

  pipeline_id_ex.memtoreg(mtrsg);
  tb.mtrout(mtrsg);

  pipeline_id_ex.aluop1(a1);
  tb.a1out(a1);

  pipeline_id_ex.aluop2(a2);
  tb.a2out(a2);

  pipeline_id_ex.aluop3(a3);
  tb.a3out(a3);

  pipeline_id_ex.alusrc(asrcsg);
  tb.asrcout(asrcsg);

  pipeline_id_ex.memwrite(mwsg);
  tb.mwout(mwsg);
//////////////////////////////////////////////
/////////////////////////////////////////////
////////////////////////////////////////////
  pipeline_id_ex.inst1alu(inst1sg);
  tb.inst1in(inst1sg);

  pipeline_id_ex.inst2alu(inst2sg);
  tb.inst2in(inst2sg);

  pipeline_id_ex.inst3alu(inst3sg);
  tb.inst3in(inst3sg);

  pipeline_id_ex.inst4alu(inst4sg);
  tb.inst4in(inst4sg);

  pipeline_id_ex.rd1(rd1sg);
  tb.rd1in(rd1sg);

  pipeline_id_ex.rd2(rd2sg);
  tb.rd2in(rd2sg);

  pipeline_id_ex.ig(igsg);
  tb.igin(igsg);

  pipeline_id_ex.bp(bps);
  tb.bin(bps);

  pipeline_id_ex.mrp(mrpsg);
  tb.mrin(mrpsg);

  pipeline_id_ex.mtrp(mtrpsg);
  tb.mtrin(mtrpsg);

  pipeline_id_ex.alu1(alu1sg);
  tb.a1in(alu1sg);

  pipeline_id_ex.alu2(alu2sg);
  tb.a2in(alu2sg);

  pipeline_id_ex.alu3(alu3sg);
  tb.a3in(alu3sg);

  pipeline_id_ex.mwp(mwpsg);
  tb.mwin(mwpsg);

  pipeline_id_ex.as(assg);
  tb.asrcin(assg);
/*
  pipeline_id_ex.inst1(i1sg);
  pipeline_id_ex.inst2(i2sg);
  pipeline_id_ex.inst3(i3sg);
  pipeline_id_ex.inst4(i4sg);
  pipeline_id_ex.readdata1(readdata1sg);
  pipeline_id_ex.readdata2(readdata2sg);
  pipeline_id_ex.immgen(immgensg);
  pipeline_id_ex.branch(bsg);
  pipeline_id_ex.memread(mrsg);
  pipeline_id_ex.memtoreg(mtrsg);
  pipeline_id_ex.aluop1(a3);
  pipeline_id_ex.aluop2(a2);
  pipeline_id_ex.aluop3(a1);
  pipeline_id_ex.memwrite(mwsg);
  pipeline_id_ex.alusrc(asrcsg);

  pipeline_id_ex.inst1alu(inst1sg);
  pipeline_id_ex.inst2alu(inst2sg);
  pipeline_id_ex.inst3alu(inst3sg);
  pipeline_id_ex.inst4alu(inst4sg);
  pipeline_id_ex.rd1(rd1sg);
  pipeline_id_ex.rd2(rd2sg);
  pipeline_id_ex.ig(igsg);
  pipeline_id_ex.bp(bps);
  pipeline_id_ex.mrp(mrpsg);
  pipeline_id_ex.mtrp(mtrpsg);
  pipeline_id_ex.alu1(alu1sg);
  pipeline_id_ex.alu2(alu2sg);
  pipeline_id_ex.alu3(alu3sg);
  pipeline_id_ex.mwp(mwpsg);
  pipeline_id_ex.as(assg);
  

  tb.inst1in(inst1sg);
  tb.inst2in(inst2sg);
  tb.inst3in(inst3sg);
  tb.inst4in(inst4sg);
  tb.rd1in(rd1sg);
  tb.rd2in(rd2sg);
  tb.igin(igsg);
  tb.bin(bps);
  tb.mrin(mrpsg);
  tb.mtrin(mtrsg);
  tb.a1in(alu1sg);
  tb.a2in(alu2sg);
  tb.a3in(alu3sg);
  tb.mwin(mwpsg);
  tb.asrcin(assg);

  tb.inst1out(i1sg);
  tb.inst2out(i2sg);
  tb.inst3out(i3sg);
  tb.inst4out(i4sg);
  tb.rd1out(readdata1sg);
  tb.rd2out(readdata2sg);
  tb.igout(immgensg);
  tb.bout(bsg);
  tb.mrout(mrsg);
  tb.mtrout(mtrpsg);
  tb.mtrin(mtrsg);
  tb.a1out(a3);
  tb.a2out(a2);
  tb.a3out(a1);
  tb.mwout(mwsg);
  tb.asrcout(asrcsg);
*/
  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();



















































































































































// id/ex - ex/mem





















































































































































// ex/mem - mem/wb











































































































































    return 0;
}








