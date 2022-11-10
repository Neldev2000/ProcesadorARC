#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    std::vector<string> respaldo;
    string linea;
    string texto = "añade esto";

  ifstream myfile("example.txt"); 
  
 while (getline(myfile,linea))
 {
    respaldo.push_back(linea);

 }

 for (int i = 0; i < respaldo.size(); i++)
 {
   cout << "\nfrase " << (i+1) << " :" <<respaldo[i] << "\n";
 }
 

  ofstream miarchivo;
  miarchivo.open ("example.txt"); 

   for (int o = 0; o < respaldo.size(); o++)
   {
    miarchivo << respaldo[o]<<"\n";
   }

    miarchivo << texto; 
  myfile.close();


 return 0;
}
