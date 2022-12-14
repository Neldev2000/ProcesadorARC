#include "InstructionMemory.h"
#include <iostream>
#include <stdlib.h>
#define charToInt(x) (int)(x - '0')
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
map<string, string> funct3Map = {
    {"add" , "000"},{"sub"  , "000"}, {"sll", "001"}, {"or"  , "110"}, {"and", "111"}, {"slt" , "010"},
    {"addi", "000"}, {"slli", "001"}, {"ori", "110"}, {"slti", "010"}, {"lw" , "010"}, {"jalr", "000"},
    {"sw"  , "010"},
    {"beq" , "000"}, {"bne" , "001"}, {"blt", "100"},
    {"jal" , "000"} 
};

map<string, string> funct7Map = {
    {"add" , "0000000"},{"sub"  , "0100000"}, {"sll", "0000000"}, {"or"  , "0000000"}, {"and", "111"}, {"slt" , "010"},
    {"addi", "1111111"}, {"slli", "1111111"}, {"ori", "1111111"}, {"slti", "1111111"}, {"lw" , "1111111"}, {"jalr", "1111111"},
    {"sw"  , "1111111"},
    {"beq" , "1111111"}, {"bne" , "1111111"}, {"blt", "1111111"},
    {"jal" , "1111111"} 
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
    i30("i30"), i14("i14"), i13("i13"), i12("i12"), i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    rs1("rs1"),
    rs2("rs2"),
    rd("rd"),
    immGen("ImmGen")

{
    SC_METHOD(process);
    
    sensitive << programCounterIndex;
    dont_initialize();
}
void InstructionMemory::process() {
   // instructionDistribution.write(  ~programCounterIndex.read());
    string instruction = this->getInstruction();
    if(instruction.length() == 0)
        exit(EXIT_FAILURE);
    cout << "======================================================="
        << "\nInstructionMemory: \n" << instruction << " " << " -> ";
    vector< string > wordList;
    this->parseInstruction(instruction, wordList);

    string functType = this->getFunctionType(wordList[0]);

    sc_bv<32> bitList;
    this->encodeInstruction(functType, wordList, bitList);
    std::cout << bitList << endl;
    i30.write(bitList.range(30,30).to_int());
    i14.write(bitList.range(14,14).to_int());
    i13.write(bitList.range(13,13).to_int());
    i12.write(bitList.range(12,12).to_int());

    i6.write(bitList.range(6,6).to_int());
    i5.write(bitList.range(5,5).to_int());
    i4.write(bitList.range(4,4).to_int());
    i3.write(bitList.range(3,3).to_int());
    i2.write(bitList.range(2,2).to_int());

    rs1.write(bitList.range(19,15));
    rs2.write(bitList.range(24,20));
    rd.write(bitList.range(11,7));

    immGen.write( bitList.range(31,20) );
    
}
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
string InstructionMemory::getInstruction() {
    int line = programCounterIndex.read().to_int() / 4;
    //line = (line == 0? 1 : line);
    
    string instruction;
   
    programFile.open("program.txt");
    for(int i = 0; i <= line; i++){
        if(!programFile.eof())
            getline(programFile, instruction);
    }
    cout << "linea a ejecutar :" << line << endl;
    programFile.close();
    return instruction;

}

void InstructionMemory::parseInstruction(string& instruction, vector<string>& wordList) {
    string word="";

    for(auto x: instruction) {
      if(x == ' ' or x == ',' or x == '(' or x == ')'){
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
void InstructionMemory::encodeInstruction(const string& instType, const vector<string>& wordList, sc_bv<32>& bitList) {
    string funct7 = funct7Map[wordList[0]];
    string funct3 = funct3Map[wordList[0]];
    string opcode = opCodeMap[wordList[0]];
    
    if(instType == "r"){
        // funct7 + rs2 + rs1 + funct3 + rd + opcode

        sc_bv<5> rs1( stringNumberToInt(wordList[2].substr(1)) );
        sc_bv<5> rs2( stringNumberToInt(wordList[3].substr(1)) );
        sc_bv<5> rd(  stringNumberToInt(wordList[1].substr(1)) );
      //  string res = funct7 + rs2.to_string() + rs1.to_string() + funct3 + rd.to_string() + opcode ;
        sc_bv<32> temp((funct7 + rs2.to_string() + rs1.to_string() + funct3 + rd.to_string() + opcode).c_str());
        bitList = temp;
       // bitList = funct7 + rs2.to_string() + rs1.to_string() + funct3 + rd.to_string() + opcode;
    }
    else if( instType == "l" ){
      //rd, rs1, imm
      //rd, imm(rs1)
      //imm [11:0] + rs1 + funct3 + rd + opcode
      sc_bv<12> imm( (wordList[0] == "lw")? (stringNumberToInt(wordList[2])) : (stringNumberToInt(wordList[3])) );
      sc_bv<5> rs1((wordList[0] == "lw")? (stringNumberToInt(wordList[3].substr(1))) : (stringNumberToInt(wordList[2].substr(1))));
      sc_bv<5> rd( stringNumberToInt(wordList[1].substr(1)));
       
      sc_bv<32> temp( ( imm.to_string() + rs1.to_string() + funct3 + rd.to_string() + opcode ).c_str() );
      bitList = temp;
    }
    else if(instType == "s") {
      // sw rs2, imm(rs1)
      // imm [11:5] + rs2 + rs1 + funct3 + imm[4:0]
      
      sc_bv<12> imm(stringNumberToInt(wordList[2]));
      sc_bv<5> rs1(stringNumberToInt(wordList[3].substr(1)));
      sc_bv<5> rs2(stringNumberToInt(wordList[1].substr(1)));
      sc_bv<32> temp((imm.range(11,5).to_string() +rs2.to_string() + rs1.to_string() + funct3 + imm.range(4,0).to_string()+opcode ).c_str());
      bitList = temp;
    }
    else if(instType == "sb"){
      //beq rs1, rs2, imm
      // 0   1   2     3
      //imm [12] + imm[10:5] + rs2 + rs1 + funct3 + imm[4:1] + imm[11] + opcode
      sc_bv<13> imm( stringNumberToInt(wordList[3]) );
      sc_bv<5>  rs1( stringNumberToInt(wordList[1].substr(1)) );
      sc_bv<5>  rs2( stringNumberToInt(wordList[2].substr(1)) );

     
      sc_bv<32> temp( ( imm.range(12,12).to_string() + imm.range(10,5).to_string() + \
			rs2.to_string() + rs1.to_string() + funct3 +\
			imm.range(4,1).to_string() + imm.range(11,11).to_string() + opcode ).c_str());
      bitList = temp;

	}
    else if(instType == "UJ") {
      // jal x0, x0
      // 0   1   2
      // imm [20] + imm[10,1] + imm[1] + imm[19,12]+rd + opcode
      sc_bv<21> imm( stringNumberToInt(wordList[2].substr(1)) );
      sc_bv<5>  rd ( stringNumberToInt(wordList[1].substr(1)) );

      sc_bv<32> temp ( ( imm.range(20,20).to_string() + imm.range(10,1).to_string()+imm.range(1,1).to_string()+imm.range(19,12).to_string()+rd.to_string()+opcode ).c_str() );
      bitList = temp;
    }
    
}
