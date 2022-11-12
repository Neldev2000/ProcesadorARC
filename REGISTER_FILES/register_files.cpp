#include "register_files.h"

register_files::register_files(sc_module_name nm) : sc_module(nm), rs1("rs1"), rs2("rs2"), rd("rd"), wd("wd"), rs1d("rs1d"), rs2d("rs2d"), register_list(32) {//inicializar puertos

  SC_METHOD(operation); // cuando las variables cambien ejecuta esa funcion
  sensitive << rs1 << rs2 << rd << wd; // estas son las que van a cambiar
  //dont_initialize();
   
}

void register_files::operation() { //  variableout.write(dato in);
  cout << "REGISTER FILE \n\n";
  leer();
  escribir();
  
  cout << "RegWrite RF: " << regwritein.read() << endl
   << "rd " << rd.read() << endl
   << "wd " << wd.read() << endl
   <<"================================================\n";
}

    void register_files::leer(){

   myfile.open("write_list.txt"); 
   int a;
   for(a = 0; a<32; a++) //getline(myfile,linea)
 { 
  getline(myfile,linea,'\n');
   //register_list.push_back(linea.c_str());
   register_list[a]= linea.c_str();

 }
    myfile.close();
 
  myfile.open ("write_list.txt"); 

   for (omega = 0; omega < 32; omega++)
   {
    myfile << register_list[omega] <<"\n";
   }

  myfile.close();

    }
    void register_files::escribir(){
      rs1d.write(register_list[rs1.read().to_int()]);

      rs2d.write(register_list[rs2.read().to_int()]);
      
      if (regwritein.read() == 1){
       register_list[rd.read().to_int()]=wd;
      }
      
      myfile.open("write_list.txt"); 

   for (alpha = 0; alpha < 32; alpha++){

    myfile << register_list[alpha] <<"\n";
    
   }

  myfile.close();

    }

 