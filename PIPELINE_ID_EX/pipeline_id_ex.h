#ifndef PIPELINE_ID_EX
#define PIPELINE_ID_EX

#include <systemc.h>
#include <vector>
#include<string>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

class pipeline_id_ex: public sc_module {
  public:
    sc_in<bool> inst1, inst2, inst3, inst4, branch, memread, memtoreg, aluop1, aluop2, aluop3, memwrite, alusrc;
    sc_in<sc_bv<32>> readdata1, readdata2, immgen;
//----------------------------------------------------------------------------------------------------------------
    sc_out<bool> inst1alu,  inst2alu, inst3alu, inst4alu, bp, mrp, mtrp, alu1, alu2, alu3, mwp, as;
    sc_out<sc_bv<32>> rd1, rd2, ig, igmux, rd2mux;

    SC_CTOR(pipeline_id_ex);

/*
inst1("inst1"),inst2("inst2"), inst3("inst3"), inst4("inst4"), branch("branch"), memread("memread"), memtoreg("memtoreg"), aluop1("aluop1"), aluop2("aluop2"), aluop3("aluop3"), memwrite("memwrite"), alusrc("alusrc"), readdata1("readdata1"), readdata2("readdata2"), immgen("immgen"), inst1alu("inst1alu"),  inst2alu("inst2alu"), inst3alu("inst3alu"), inst4alu("inst4alu"), bp("bp"), mrp("mrp"), mtrp("mtrp"), alu1("alu1"), alu2("alu2"), alu3("alu3"), mwp("mwp"), as("as"), rd1("rd1"), rd2("rd2"), ig("ig");
<< inst1 << inst2 << inst3 << inst4 << branch << memread << memtoreg << aluop1 << aluop2 << aluop3 << memwrite << alusrc << readdata1 << readdata2 << immgen
*/

  private:
    void operation();
    void trigger();
  
};

#endif