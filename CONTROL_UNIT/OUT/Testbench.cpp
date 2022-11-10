#include "Testbench.h"

Testbench::Testbench(sc_module_name modName):
    sc_module(modName),
    i6("i6"), i5("i5"), i4("i4"), i3("i3"), i2("i2"),
    aluOp2("aluOp2")
    ,clock("clock")
{

    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();

}

void Testbench::test() {
 
    cout << "i6 | i5 | i4 | i3 | i2 ||  ALUOp2 | \n";

    for(int i = 0; i < 12; i++){
        setData(i);
        wait();
        print(i);
    }
}
void Testbench::print(int i) {
    bool aluOp2Res[]   = {0,0,0,0,0,0,0,0,1,0,1,1};


    cout << std::setw(2) << std::setfill('0') << i6.read() << " | "
         << std::setw(2) << std::setfill('0') << i5.read() << " | "
         << std::setw(2) << std::setfill('0')<< i4.read() << " | "
         << std::setw(2) << std::setfill('0')<< i3.read() << " | "
         << std::setw(2) << std::setfill('0')<< i2.read() << " || "
         << (aluOp2.read() == aluOp2Res[i]? "vvvvvv" : "xxxxxx") << " | "<< endl; 
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

