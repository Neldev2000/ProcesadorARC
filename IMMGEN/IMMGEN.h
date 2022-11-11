#ifndef IMM_GEN
#define IMM_GEN

//para a;adir el set data struct
#include <systemc.h>
class IMMGEN : public sc_module
{
public:
    SC_CTOR(IMMGEN);

    sc_in<sc_bv<12>> inex;

    sc_out<sc_bv<32>> outex;

private:

    void process();
};


#endif //INSTRUCTION_MEMORY_H
