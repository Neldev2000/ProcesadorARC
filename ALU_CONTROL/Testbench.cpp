#include "Testbench.h"

Testbench::Testbench(sc_module_name modName):
    sc_module(modName),
    aluOp0("ALUOp0"),aluOp1("ALUOp1"), aluOp2("ALUOp2"), aluOp3("aluOp3"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    aluF0("aluF0"), aluF1("aluF1"), aluF2("aluF2"),
    clock("clock")
{

    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();

}

void Testbench::test() {
 
    cout << "A3 | A2 | A1 | A0 || I30 | I14 | I13 | I12 || S |\n";

    for(int i = 0; i < 12; i++){
        setData(i);
        wait();
        print(i);
    }
}
void Testbench::print(int i) {

    bool s2[] = {0,0,0,0,1,1,1,1,1,0,0,1,0,1,1};

    cout 
        << std::setw(2) << std::setfill('0') << aluOp2.read() << " | "
         << std::setw(2) << std::setfill('0')<< aluOp1.read() << " | "
         << std::setw(2) << std::setfill('0')<< aluOp0.read() << " || "
         << std::setw(3) << std::setfill('0')<< this->i30.read() << " | "
        << std::setw(3) << std::setfill('0')<< this->i14.read() << " | "
        << std::setw(3) << std::setfill('0')<< this->i13.read() << " | "
        << std::setw(3) << std::setfill('0')<< this->i12.read() << " || "
        << std::setw(1) << std::setfill('0')<< ((aluF2.read() == s2[i])? "vv" : "xx") << " | \n" ;

}
void Testbench::setData(int i) {
    bool a2[] = {0,0,0,0,1,1,1,1,1,1,1,1,1,1};
    bool a1[] = {0,0,1,1,0,0,1,1,1,1,1,1,1,1};
    bool a0[] = {0,1,0,1,0,1,0,1,1,1,1,1,1,1};

    bool i30[] ={0,0,0,0,0,0,0,0,0,1,0,0,0,0};
    bool i14[] ={0,0,0,0,0,0,0,0,0,0,0,1,1,0};
    bool i13[] ={0,0,0,0,0,0,0,0,0,0,0,1,1,1};
    bool i12[] ={0,0,0,0,0,0,0,0,0,0,1,0,1,0};



    aluOp0.write(a0[i]);
    aluOp1.write(a1[i]);
    aluOp2.write(a2[i]);

    this->i30.write(i30[i]);
    this->i14.write(i14[i]);
    this->i13.write(i13[i]);
    this->i12.write(i12[i]);

}

