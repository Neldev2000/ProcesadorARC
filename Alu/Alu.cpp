#include "Alu.h"


Alu::Alu(sc_module_name nm):sc_module(nm), res("res"), zero("zero"), rs1("rs1"), rs2("rs2"),aluOp1("aluOp1"),aluOp2("aluOp2"),aluOp3("aluOp3") {
	SC_METHOD(operacion);
    
    sensitive << rs1 << rs2 << aluOp1 <<aluOp2 <<aluOp3;
	dont_initialize();
}

void Alu::operacion(){

	if(aluOp1.read() == false && aluOp2.read() == false && aluOp3.read() == false){  
    	sc_bv<32> test;
		bool val;
    	suma(test,val);
    	res.write(test);
		zero.write(val);
  	} 
  
  	if(aluOp1.read() == false && aluOp2.read() == false && aluOp3.read() == true){  
    	sc_bv<32> test;
		bool val;
    	resta(test,val);
    	res.write(test);
		zero.write(val);
  	} 
	
	if(aluOp1.read() == false && aluOp2.read() == true && aluOp3.read() == false){  
    	sc_bv<32> test;
		bool val;
    	bne(test,val);
    	res.write(test);
		zero.write(val);
  	}

	if(aluOp1.read() == false && aluOp2.read() == true && aluOp3.read() == true){  
    	sc_bv<32> test;
		bool val;
    	orBit(test,val);
    	res.write(test);
		zero.write(val);
  	}

	if(aluOp1.read() == true && aluOp2.read() == false && aluOp3.read() == false){  
    	sc_bv<32> test;
		bool val;
    	desplazarIzq(test,val);
    	res.write(test);
		zero.write(val);
  	}

	if(aluOp1.read() == true && aluOp2.read() == false && aluOp3.read() == true){  
    	sc_bv<32> test;
		bool val;
    	menorQue(test,val);
    	res.write(test);
		zero.write(val);
  	}

	if(aluOp1.read() == true && aluOp2.read() == true && aluOp3.read() == false){  
    	sc_bv<32> test;
		bool val;
    	asignar(test,val);
    	res.write(test);
		zero.write(val);
  	}

	if(aluOp1.read() == true && aluOp2.read() == true && aluOp3.read() == true){  
    	sc_bv<32> test;
		bool val;
    	andBit(test,val);
    	res.write(test);
		zero.write(val);
  	}

	cout << "ALU: "<< res.read() << endl
		<< "-------------\n";
}

//@@@ Metodo Sumar(Instrucciones: add,addi,lw,sw,jalr)

void Alu::suma(sc_bv<32>& test, bool& val){
	sc_uint<32> data = rs1.read().to_int() + rs2.read().to_int();
	test = data;
	val = true;
}

//@@@ Metodo Resta(Instrucciones: sub, beq)

void Alu::resta(sc_bv<32>& test, bool& val){ 
	sc_uint<32> data = rs1.read().to_int()-rs2.read().to_int();
  	test = data;
	if( test.to_int() == 0){
		val = true;	
	}
	if(test.to_int() != 0){
		val = false;
	}

}

//@@@ Metodo Desplazar a la Izquierda(Instrucciones: sll,slli)

void Alu::desplazarIzq(sc_bv<32>& test, bool& val){ 
	sc_uint<32> data = rs1.read() <<  rs2.read().to_int();
	test = data;
	val = false;
}

//@@@ Metodo Or Bit a Bit(Instrucciones: or,ori)

void Alu::orBit(sc_bv<32>& test, bool& val){ 
	sc_uint<32> data = rs1.read() |  rs2.read();
	test = data;
	val = false;
}

//@@@ Metodo And Bit a Bit(Instrucciones: and)

void Alu::andBit(sc_bv<32>& test, bool& val){
	sc_uint<32> data = rs1.read() &  rs2.read();
  	test = data;
	val = false;
}


//@@@ Metodo Si NO Son Iguales(Instrucciones: bne)

void Alu::bne(sc_bv<32>& test, bool& val){
	if ( rs1.read() !=  rs2.read()){
		test = "1";
		val = true;
	}else{
		test = "0";
		val = false;
	}	
}

//@@@ Metodo Menor Que(Instrucciones: blt,slt,slti)

void Alu::menorQue(sc_bv<32>& test, bool& val){
	if ( rs1.read().to_int() <  rs2.read().to_int()){
		test = "1";
		val = true;
	}else{
		test = "0";
		val = false;
	}	
}

//@@@ Metodo Asignar(Instrucciones: jal)

void Alu::asignar(sc_bv<32>& test, bool& val){
	test = rs2.read();
	val = true;
}

