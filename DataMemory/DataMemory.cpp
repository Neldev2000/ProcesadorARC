#include "DataMemory.h"


DataMemory::DataMemory(sc_module_name nm):sc_module(nm), readData("readData"), data(3){
	SC_METHOD(operacion);
    dont_initialize();
    sensitive << address << writeData << memWrite << memRead;
   // data[0]= "101011";
    //data[1] = "010101";
}

void DataMemory::operacion(){
    leer();
     std::cout <<"Data: " << data[0]<< "\n";
  std::cout <<"Data: " << data[01]<< "\n";
   std::cout <<"Data: " << data[2]<< "\n";
    if(memRead == true){
        readData.write( data[address.read().to_int()]); 
    }
    if(memWrite == true){
        data[address.read().to_int()] = writeData.read(); 


        readData.write("0");
    }
    escribir();
}
void DataMemory::escribir(){
    archivo.open ("datamemory.txt");
    for(int i = 0; i < 3;i++){
            archivo << data[i].to_string()<< endl; 
    } 
    archivo.close();    
}
void DataMemory::leer(){
    archivo.open ("datamemory.txt");
    std::string n;

    for(int i = 0; i < 3;i++){
        std::getline(archivo, n,'\n');
        data[i] = n.c_str();
    }
    archivo.close();  
}

