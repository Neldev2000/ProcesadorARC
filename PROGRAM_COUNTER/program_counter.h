#ifndef PROGRAM_COUNTER
#define PROGRAM_COUNTER

#include <systemc.h>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

class program_counter: public sc_module {
  public:
    sc_in<sc_bv<32>> inpc;
    sc_out<sc_bv<32>> outpc;
  //  sc_out<sc_bv<32>> outpc;

    SC_CTOR(program_counter);


  private:
    void operation();
    //std::vector <sc_bv<32>> program_counter;
};

#endif