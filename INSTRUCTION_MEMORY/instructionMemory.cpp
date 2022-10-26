#include "instructionMemory.h"
#define charToInt(x) x - '0'
using namespace std;
set<string> rType = {"add", "sub", "sll", "or", "and", "slt" };
set<string> lType = {"addi", "slli", "ori", "slti", "lw", "jalr"};
set<string> sType = {"sw"};
set<string> sbType = {"beq", "bne", "blt"};
set<string> ubType = {"jal"};


map<string, string> opCodeMap = {
    {"add" , "0110011"},{"sub"  , "0110011"}, {"sll", "0110011"}, {"or"  , "0110011"}, {"and", "0110011"}, {"slt" , "0110011"},
    {"addi", "0010011"}, {"slli", "0010011"}, {"ori", "0010011"}, {"slti", "0010011"}, {"lw" , "0000011"}, {"jalr", "1100111"},
    {"sw"  , "0100011"},
    {"beq" , "1100111"}, {"bne" , "1100111"}, {"blt", "1100111"},
    {"jal" , "1101111"} 
};


int stringNumberToInt(const string& str) {
    int decimals = str.length();
    int res = 0;
    int k = 1;
    for(int i = decimals-1; i>=0; i--) {
        res += k*charToInt(str[i]);
        k *=10;
    }


    return res;
}

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

    string functType = this->getFunctionType(wordList[0]);


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

string InstructionMemory::getFunctionType(const string& funct) {
   
    if(rType.find(funct) != rType.end())
        return "r";
    else if(lType.find(funct) != lType.end())
        return "l";
    else if(sType.find(funct) != sType.end())
        return "s";
    else if(sbType.find(funct)  != sbType.end())
        return "sb";
    else if(ubType.find(funct) != ubType.end())
        return "ub";
    
    return "null";
    
}
void InstructionMemory::encodeInstruction(const string& instType, const vector<string>& wordList) {
    if(instType == "r"){

    }
}