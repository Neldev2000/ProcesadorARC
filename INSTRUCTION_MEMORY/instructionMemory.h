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
int stringNumberToInt(const std::string&);

class InstructionMemory : public sc_module
{
public:
    SC_CTOR(InstructionMemory);
    sc_in<sc_bv<32>> programCounterIndex;
    
    sc_out<sc_bv<32>> instructionDistribution;
private:
 
    ifstream programFile;
     
    

    void process();

    std::string getInstruction();
    void parseInstruction(std::string&, std::vector<std::string>& wordList);
    std::string getFunctionType(const std::string&);
    void encodeInstruction(const std::string&, const std::vector<std::string>& );
};


#endif //INSTRUCTION_MEMORY_H
