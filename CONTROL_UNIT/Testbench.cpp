#include "Testbench.h"

Testbench::Testbench(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    regWrite("regWrite"), memWrite("memWrite"), memToReg("memToReg"), memRead("memRead"), branch("branch"), 
    aluSrc("aluSrc"), aluOp3("aluOp3"), aluOp2("aluOp2"), aluOp1("aluOp1"), aluOp0("aluOp0")
    ,clock("clock")
{

    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();

}

void Testbench::test() {
 
    cout << "i6 | i5 | i4 | i3 | i2 || ALUSrc | MemtoReg | RegWrite | MemRead | MemWrite | Branch | ALUOp3 | ALUOp2 | ALUOp1 | ALUOp0 | \n";

    for(int i = 0; i < 12; i++){
        setData(i);
        wait();
        print(i);
    }
}
void Testbench::print(int i) {

    bool regWriteRes[] = {1,1,0,0,0,1,1,1,0,0,1,1};
    bool memWriteRes[] = {0,0,1,0,0,0,0,0,0,0,0,0};
    bool memToRegRes[] = {0,1,0,0,0,0,0,0,0,0,0,0};
    bool memReadRes[]  = {0,1,0,0,0,0,0,0,0,0,0,0};
    bool branchRes[]   = {0,0,0,1,1,0,0,0,1,1,0,0};
    bool aluSrcRes[]   = {1,1,1,0,0,1,1,1,0,0,1,0};
    bool aluOp3Res[]   = {0,0,0,0,0,0,0,0,0,0,0,1};
    bool aluOp2Res[]   = {0,0,0,0,0,0,1,1,1,1,1,0};
    bool aluOp1Res[]   = {0,0,0,0,1,1,0,0,0,1,1,0};
    bool aluOp0Res[]   = {0,0,0,1,0,1,0,1,1,0,0,0};
    


    cout << std::setw(2) << std::setfill('0') << i6.read() << " | "
         << std::setw(2) << std::setfill('0') << i5.read() << " | "
         << std::setw(2) << std::setfill('0')<< i4.read() << " | "
         << std::setw(2) << std::setfill('0')<< i3.read() << " | "
         << std::setw(2) << std::setfill('0')<< i2.read() << " || "
         << (aluSrc.read() == aluSrcRes[i]? "vvvvvv" : "xxxxxx") << " | "
         << (memToReg.read() == memToRegRes[i]? "vvvvvvvv" : "xxxxxxxx") << " | "
         << (regWrite.read() == regWriteRes[i]? "vvvvvvvv" : "xxxxxxxx") << " | "
         << (memRead.read() == memReadRes[i]? "vvvvvvv" : "xxxxxxx") << " | "
         << (memWrite.read() == memWriteRes[i]? "vvvvvvvv" : "xxxxxxxx") << " | "
         << (branch.read() == branchRes[i]? "vvvvvv" : "xxxxxx") << " | "
         << (aluOp3.read() == aluOp3Res[i]? "vvvvvv" : "xxxxxx") << " | "
         << (aluOp2.read() == aluOp2Res[i]? "vvvvvv" : "xxxxxx") << " | "
         << (aluOp1.read() == aluOp1Res[i]? "vvvvvv" : "xxxxxx") << " | "
         << (aluOp0.read() == aluOp0Res[i]? "vvvvvv" : "xxxxxx") << " | " << endl; 
}
void Testbench::setData(int i) {

    bool i6[] ={0,0,0,1,1,0,0,0,1,1,1,0};
    bool i5[] ={0,0,1,1,1,0,0,0,1,1,1,1};
    bool i4[] ={1,0,0,0,0,1,1,1,0,0,0,1};
    bool i3[] ={0,0,0,0,0,0,0,0,0,0,1,0};
    bool i2[] ={0,0,0,1,1,0,0,0,0,1,1,0};

    this->i6.write(i6[i]);
    this->i5.write(i5[i]);
    this->i4.write(i4[i]);
    this->i3.write(i3[i]);
    this->i2.write(i2[i]);

}

