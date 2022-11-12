#include "TestBench.h"

TestBench::TestBench(sc_module_name modName): sc_module(modName), starter("starter"){

    SC_THREAD(test);

}

void TestBench::test() {
    starter.write("1");
    wait();
}