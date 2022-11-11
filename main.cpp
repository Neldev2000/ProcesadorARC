// montando el main principal
//0 - if/id



















































































































































// if/id - id/ex


  sc_time period(10, SC_NS);
  sc_time delay(0, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  pipeline_if_id pipeline_if_id("pipe_ifid");
  ControlUnit controlUnit("controlUnit");
  register_files registerfiles("reg_fil");
  immgen immgen("immgen");
  pipeline_id_ex pipeline_id_ex("pipe_idex");


  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> it1, it2, it3, it4, cib2, cib3, cib4, cib5, cib6, cdregister, cmw, cmtr, cmr, cb, cas, cao2, cao1, cao0;
  sc_signal<sc_bv<5>> crs1, crs2, crd ;
  sc_signal<sc_bv<12>> cgenin;
  sc_signal<sc_bv<32>> crd1, crd2, coutgen;

  //sc_signal<bool> fSg;

  // Conectando los módulos a los cables modulo.

 //pipeline_if_id pipeline_if_id.puerto(cable);

   pipeline_if_id.i12out(it1);
   pipeline_if_id.i13out(it2);
   pipeline_if_id.i14out(it3);
   pipeline_if_id.i30out(it4);

   pipeline_if_id.i2out(cib2);
   pipeline_if_id.i3out(cib3);
   pipeline_if_id.i4out(cib4);
   pipeline_if_id.i5out(cib5); 
   pipeline_if_id.i6out(cib6);  

   pipeline_if_id.imoutrs1(crs1);
   pipeline_if_id.imoutrs2(crs2);
   pipeline_if_id.imoutrd(crd);

   pipeline_if_id.imoutgen(cgenin); 


   // controlUnit.puerto(cable);

   controlUnit.i2(cib2);
   controlUnit.i3(cib3);
   controlUnit.i4(cib4);
   controlUnit.i5(cib5);
   controlUnit.i6(cib6);

   controlUnit.regwrite(cdregister);
   controlUnit.memwrite(cmw);
   controlUnit.memtoreg(cmtr);
   controlUnit.memread(cmr);
   controlUnit.branch(cb);
   controlUnit.alusrc(cas);
   controlUnit.aluop2(cao2);
   controlUnit.aluop1(cao1);
   controlUnit.aluop0(cao0);

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
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();



















































































































































// id/ex - ex/mem





















































































































































// ex/mem - mem/wb
















































































































































