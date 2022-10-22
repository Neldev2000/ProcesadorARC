#ifndef REGISTER_FILES
#define REGISTER_FILES

#include <systemc.h>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

class Register_Files: public sc_module {
  public:
    sc_in<sc_bv<5>> rs1, rs2, rd;
    sc_in<sc_bv<32>> wd;
    sc_out<sc_bv<32>> rs1d,rs2d;

    SC_CTOR(Register_Files);
    ~Register_Files();

  private:
    void operation();
    std::vector <sc_bv<32>> register_list;
};