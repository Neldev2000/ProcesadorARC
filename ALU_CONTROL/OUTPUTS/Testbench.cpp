#include "Testbench.h"

Testbench::Testbench(sc_module_name modName):
    sc_module(modName),
    s("s"),
    aluOp0("A0"),aluOp1("A1"), aluOp2("A2"),
    i30("i30"), i14("i14"), i13("i13"), i12("i12"),
    clock("clock")
{

    SC_THREAD(test);
    dont_initialize();
    sensitive << clock.pos();

}

void Testbench::test() {
    cout << "A0 | A1 | A2 || I30 || I14 | I13 | I12 ||| S |" << endl;
    
    for(int i = 0; i < 12; i++){
        setData(i);
        wait();
        wait();
        print();
    }

}
void Testbench::print() {
    cout << setw(2) << aluOp0.read() << " | " 
        << setw(2) << aluOp1.read() << " | " 
        << setw(2) << aluOp2.read() << " || " 
        << setw(3) << i30.read() << " || " 
        << setw(3) << i14.read() << " | " 
        << setw(3) << i13.read() << " | " 
        << setw(3) << i12.read() << " ||| " 
        << setw(1) << s.read() << " |\n";

}

void Testbench::setData(int i) {
    bool a0[] = {0,0,0,1,1,1,0,0,0,0,0,0};
    bool a1[] = {0,1,1,0,0,1,0,0,0,0,0,0};
    bool a2[] = {1,0,1,0,1,1,0,0,0,0,0,0};
    bool i30[] ={1,1,1,1,1,1,0,1,0,0,0,0};
    bool i14[] ={1,1,1,1,1,1,0,0,0,1,1,0};
    bool i13[] ={1,1,1,1,1,1,0,0,0,1,1,1};
    bool i12[] ={1,1,1,1,1,1,0,0,1,0,1,0};

    aluOp0.write(a0[i]);
    aluOp1.write(a1[i]);
    aluOp2.write(a2[i]);

    this->i30.write(i30[i]);
    this->i14.write(i14[i]);
    this->i13.write(i13[i]);
    this->i12.write(i12[i]);
}