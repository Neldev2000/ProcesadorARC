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
    
    //

private:
 
    ifstream programFile;
     
    

    void process();

    std::string getInstruction();
    void parseInstruction(std::string&, std::vector<std::string>& wordList);
    std::string getFunctionType(const std::string&);
    void encodeInstruction(const std::string&, const std::vector<std::string>&, sc_bv<32>& bitList);
};


#endif //INSTRUCTION_MEMORY_H
