#ifndef ALU_H
#define ALU_H

#include <systemc.h>



class Alu: public sc_module {
    public:
        sc_in<sc_bv<32>> rs1, rs2;
		sc_in <bool> aluOp1, aluOp2,aluOp3;
    	sc_out<sc_bv<32>> res;
		sc_out<bool> zero;

    	SC_CTOR(Alu);
	private:
		void operacion();
    	void suma(sc_bv<32>& test, bool& val);
		void resta(sc_bv<32>& test, bool& val);
		void desplazarIzq(sc_bv<32>& test, bool& val);
		void orBit(sc_bv<32>& test, bool& val);
		void andBit(sc_bv<32>& test, bool& val);
		void bne(sc_bv<32>& test, bool& val);
		void menorQue(sc_bv<32>& test, bool& val);
		void asignar(sc_bv<32>& test, bool& val);
		
};
#endif 