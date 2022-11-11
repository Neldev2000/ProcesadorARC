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
    sc_in<bool>  i30, i14, i13, i12;
    sc_in<bool> i6, i5, i4, i3, i2;
    sc_in<sc_bv<5>>  iminrd , iminrs2, iminrs1;
    
    sc_in<sc_bv<12>> imingen;

    sc_out<bool>  i30Out, i14Out, i13Out, i12Out;
    sc_out<bool> i6Out, i5Out, i4Out, i3Out, i2Out;
    sc_out<sc_bv<5>> imoutrd, imoutrs2, imoutrs1;
    sc_out<sc_bv<12>> imoutgen;

    SC_CTOR(pipeline_if_id);


  private:
    void operation();
};

#endif