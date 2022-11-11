#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H
/* code */
#include <systemc.h>
#include <fstream>
#include <string>
//TODO: Leer atchivo .asc
#include <map>

#include <bits/stdc++.h>



/*
    FUNCIONES A EJECUTAR
        add
        addi
        sub
        sll
        

*/

class InstructionMemory : public sc_module
{
public:
    SC_CTOR(InstructionMemory);
    sc_in<sc_bv<32>> programCounterIndex;
    
    // 00-06 Unidad de Control (7 bits)
    // 19-15 Rs1 (5 bits)
    // 24-20 Rs2 (5 bits) 
    // 11-07 Rd (5 bits)
    // 31-00 Imm Gen (32 bits)

    sc_out<bool> i30, i14, i13, i12, i6, i5, i4, i3, i2;
    sc_out<sc_bv<5>> rs1, rs2, rd;
    sc_out<sc_bv<12>> immGen;


private:
 
    ifstream programFile;
     
    

    void process();

    std::string getInstruction();
    void parseInstruction(std::string&, std::vector<std::string>& wordList);
    std::string getFunctionType(const std::string&);
    void encodeInstruction(const std::string&, const std::vector<std::string>&, sc_bv<32>& bitList);
};

int stringNumberToInt(const std::string&);

#endif //INSTRUCTION_MEMORY_H
