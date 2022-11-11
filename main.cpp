#include "utils.h"

int sc_main(int argc, char const *argv[])
{
    // IF-ID
    pipeline_if_id pipelineIfId("pipelineIfId");
    InstructionMemory instructionMemory("instructionMemory");

    //Conectar Instruction Memory con Pipeline

    sc_signal<bool> channelI30, channelI14, channelI13, channelI12;
    sc_signal<bool> channelI6, channelI5, channelI4, channelI3, channelI2;
    sc_signal<sc_bv<5>> channelRs1, channelRs2, channelRd;
    sc_signal<sc_bv<12>> channelImmGen;

    instructionMemory.i30(channelI30);
    pipelineIfId.i30(channelI30);

    instructionMemory.i14(channelI14);
    pipelineIfId.i14(channelI14);
    
    instructionMemory.i13(channelI13);
    pipelineIfId.i13(channelI13);

    instructionMemory.i12(channelI12);
    pipelineIfId.i12(channelI12);

/// --------------------------------------------

    instructionMemory.i6(channelI6);
    pipelineIfId.i6(channelI6);

    instructionMemory.i5(channelI5);
    pipelineIfId.i5(channelI5);

    instructionMemory.i4(channelI4);
    pipelineIfId.i4(channelI4);

    instructionMemory.i3(channelI3);
    pipelineIfId.i3(channelI3);

    instructionMemory.i2(channelI2);
    pipelineIfId.i2(channelI2);

/// --------------------------------------------
    instructionMemory.rs1(channelRs1);
    pipelineIfId.iminrs1(channelRs1);
    
    instructionMemory.rs2(channelRs2);
    pipelineIfId.iminrs2(channelRs2);

    instructionMemory.rd(channelRd);
    pipelineIfId.iminrd(channelRd);

/// --------------------------------------------

    instructionMemory.immGen(channelImmGen);
    pipelineIfId.imingen(channelImmGen);

/// --------------------------------------------
/// --------------------------------------------
/// --------------------------------------------

    program_counter programCounter("programCounter");
    Adder4 adder4("Adder4");

    sc_signal<sc_bv<32>> channelPCtoInstructionMemory, channelPCtoAdder4, channelAdder4toMux;
    
    programCounter.outInstruction(channelPCtoInstructionMemory);
    instructionMemory.programCounterIndex(channelPCtoInstructionMemory);

    programCounter.outAdd4(channelPCtoAdder4);
    adder4.pcIn(channelPCtoAdder4);

    //TODO: Conectar adder4.pcOut con mux
    //TODO: Conectar mux.Out con programCounter.inputCounter

    // IF-ID
    sc_start();
    return 0;
}













































































































































// if/id - id/ex





















































































































































// id/ex - ex/mem





















































































































































// ex/mem - mem/wb




















































































































































