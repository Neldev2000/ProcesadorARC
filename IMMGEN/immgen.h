#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <systemc.h>
#include <fstream>
#include <string>

#include <map> //para a;adir el set data struct, translate binary instruction
 
#include <bits/stdc++.h> //para a;adir el set data struct

class immgen : public sc_module
{
public:
    SC_CTOR(immgen);

    sc_in<sc_bv<12>> inex;

    sc_out<sc_bv<32>> outex;
    sc_out<sc_bv<32>> outbranch1;

private:

    void process();
};


#endif //INSTRUCTION_MEMORY_H
