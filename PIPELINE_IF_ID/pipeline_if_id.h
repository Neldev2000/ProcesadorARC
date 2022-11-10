#ifndef PIPELINE_IF_ID
#define PIPELINE_IF_ID

#include <systemc.h>
#include <vector>
#include<string>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

class pipeline_if_id: public sc_module {
  public:
    sc_in<sc_bv<4>> iminalucontrol;
    sc_in<sc_bv<5>> iminrd, iminrs2, iminrs1;
    sc_in<sc_bv<7>> imincontrol;
    sc_in<sc_bv<12>> imingen;
    sc_in<sc_bv<32>> inaddbranch;

    sc_out<sc_bv<4>> imoutalucontrol;
    sc_out<sc_bv<5>> imoutrd, imoutrs2, imoutrs1;
    sc_out<sc_bv<7>> imoutcontrol;
    sc_out<sc_bv<12>> imoutgen;
    sc_out<sc_bv<32>> outaddbranch;

    SC_CTOR(pipeline_if_id);


  private:
    void operation();
};

#endif