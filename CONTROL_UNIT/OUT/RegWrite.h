#ifndef REG_WRITE_H
#define REG_WRITE_H
 /* code */

class RegWrite : public sc_module
{
public:
    SC_CTOR(RegWrite);
    sc_in<bool> i6, i5 i4, i3, i2;
    sc_out<bool> s;
private:
    sc_vector<NotGate> notGates;
    sc_vector<OrGate> orGates;
    AndGate andGate;
    AndGate4 andGate3;
    NorGate3 norGate3;
};

#endif //REG_WRITE_H
