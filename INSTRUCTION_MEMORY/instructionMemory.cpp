#include "instructionMemory.h"

InstructionMemory::InstructionMemory(sc_module_name modName):
    sc_module(modName),
    programCounterIndex("ProgramCounterIndex"),
    instructionDistribution("InstructionDistribution")

{
    SC_METHOD(process);
    dont_initialize();
    sensitive << programCounterIndex;
}
void InstructionMemory::process() {
    instructionDistribution.write(  ~programCounterIndex.read());
    string instruction = this->getInstruction();

    vector< string > wordList;
    this->parseInstruction(instruction, wordList);

    for(string x : wordList) {
        cout << x << endl;
    }
}

string InstructionMemory::getInstruction() {
    int line = programCounterIndex.read().to_int() / 4;
    string instruction;

    programFile.open("program.txt");
    for(int i = 0; i <= line; i++)
        getline(programFile, instruction);
    
    programFile.close();
    return instruction;

}

void InstructionMemory::parseInstruction(string& instruction, vector<string>& wordList) {
    string word="";

    for(auto x: instruction) {
        if(x == ' ' or x == ','){
            wordList.push_back(word);
            word = "";
        }
        else 
            word += x;
    }
    wordList.push_back(word);
}