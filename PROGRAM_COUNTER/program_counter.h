#ifndef PROGRAM_COUNTER
#define PROGRAM_COUNTER

#include <systemc.h>


using namespace std;

class program_counter: public sc_module {
  public:
    sc_in<sc_bv<32>> inputCounter;
    sc_out<sc_bv<32>> outInstruction, outAdd4;

    SC_CTOR(program_counter);
 

  private:
     void operation();
    //std::vector <sc_bv<32>> program_counter;
};

#endif