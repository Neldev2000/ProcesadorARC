##########################################################################
# POR FAVOR, INDIQUE A CONTINUACIÓN SU CONFIGURACIÓN PARA LA COMPILACIÓN

# Versión de SYSTEMC
	VERSION = systemc-2.3.3
# Especifique los archivos .cpp
	SRCS = main.cpp ./DataMemory/DataMemory.cpp ./ALU_CONTROL/ALUControl.cpp ./ALU_CONTROL/OUT/Output0.cpp ./ALU_CONTROL/OUT/Output1.cpp ./ALU_CONTROL/OUT/Output2.cpp  ./ADDER4/Adder4.cpp ./Alu/Alu.cpp ./CONTROL_UNIT/ControlUnit.cpp ./CONTROL_UNIT/OUT/ALUOp0.cpp ./CONTROL_UNIT/OUT/ALUOp1.cpp ./CONTROL_UNIT/OUT/ALUOp2.cpp ./CONTROL_UNIT/OUT/AluSrc.cpp ./CONTROL_UNIT/OUT/Branch.cpp ./CONTROL_UNIT/OUT/MemRead.cpp ./CONTROL_UNIT/OUT/MemtoReg.cpp ./CONTROL_UNIT/OUT/MemWrite.cpp ./CONTROL_UNIT/OUT/RegWrite.cpp ./ExMem/ExMem.cpp ./GATES/AND/And.cpp ./GATES/AND/And3.cpp ./GATES/AND/And4.cpp ./GATES/AND/And5.cpp ./GATES/MUX/Mux2a1.cpp ./GATES/NAND/Nand.cpp ./GATES/NOR/Nor.cpp ./GATES/NOR/Nor3.cpp ./GATES/NOR/Nor4.cpp ./GATES/NOR/Nor5.cpp ./GATES/NOT/Not.cpp ./GATES/OR/Or.cpp ./GATES/OR/Or3.cpp ./GATES/OR/Or4.cpp ./GATES/OR/Or5.cpp ./GATES/XNOR/Xnor.cpp ./GATES/XNOR/Xnor3.cpp ./GATES/XNOR/Xnor4.cpp ./GATES/XOR/Xor.cpp ./GATES/XOR/Xor3.cpp ./GATES/XOR/Xor4.cpp ./IMMGEN/IMMGEN.cpp ./INSTRUCTION_MEMORY/InstructionMemory.cpp ./MemWb/MemWb.cpp ./PIPELINE_ID_EX/pipeline_id_ex.cpp ./PIPELINE_IF_ID/pipeline_if_id.cpp ./PROGRAM_COUNTER/program_counter.cpp ./REGISTER_FILES/register_files.cpp    
#	SRCS = ./IMMGEN/IMMGEN.cpp
# Nombre del ejecutable
	TARGET = test.out
#
# Instrucciones de uso:
# 
# El makefile le provee de varios comandos para su comodidad en la
# compilación, a continuación están más importantes:
#
# $ make
# -> Compila el proyecto según la configuración previa
#
# $ make clean
# -> Elimina todos los archivos resultantes de la compilación
#
# $ make ejemplo.o
# -> En general, puedes compilar los archivos que necesites según
#  hayas hecho cambios. Supongamos que únicamente cambiaste el main.cpp
#  puedes ejecutar "rm main.o" y luego "make main.o" en vez de
#  recompilar todos los archivos
#
# $ make run
# -> Si olvidan el nombre del ejecutable del proyecto, pueden tan solo
#  usar éste comando para ejecutarlo rápidamente, lo cual les permite
#  agilizar el tiempo del desarrollo
#######################################################################


CC  = g++
X64 = 
SYSTEMC_HOME_BY_VERSION = /usr/local/$(VERSION)

ifeq ($(shell uname -m), x86_64)
	X64 = 64
endif

ifeq ($(VERSION),systemc-2.3.1)
	CC = g++ -std=c++98
endif

INCDIR = -I. -I.. -I./IMMGEN/ -I./INSTRUCTION_MEMORY/ -I./ADDER4/ -I./Alu/ -I./ALU_CONTROL/ -I./ALU_CONTROL/OUT/ -I./CONTROL_UNIT/ -I./CONTROL_UNIT/OUT/ -I./DataMemory/ -I./ExMem/ -I./GATES/AND -I./GATES/MUX -I./GATES/NAND -I./GATES/NOR -I./GATES/NOT -I./GATES/OR -I./GATES/XNOR -I./GATES/XOR -I./MemWb/ -I./PIPELINE_ID_EX/ -I./PIPELINE_IF_ID/ -I./PROGRAM_COUNTER/ -I./REGISTER_FILES/ -I$(SYSTEMC_HOME_BY_VERSION)/include 


#INCDIR  = -I./OUT/ -I../GATES/NAND/ -I../GATES/AND/  -I../GATES/NOR -I../GATES/NOT -I../GATES/OR -I../GATES/XOR -I../GATES/XNOR -I$(SYSTEMC_HOME_BY_VERSION)/include
LIBDIR  = -L. -L.. -L$(SYSTEMC_HOME_BY_VERSION)/lib-linux$(X64)
LIBS    = -lm -lsystemc

CFLAGS  = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)
NOTDIR_OBJS = $(notdir $(OBJS))

.SUFFIXES: .cpp .o

$(TARGET): $(OBJS) $(SRCH)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(NOTDIR_OBJS) $(LIBS) 2>&1 | c++filt

all: $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(NOTDIR_OBJS) *~ $(TARGET) *.bak $(TARGET).stackdump *.vcd

run:
	./$(TARGET)