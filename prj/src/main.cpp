/*!
 *\file 
 *\brief Modul glowny.
 *
 * Plik zawiera funkcje main.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Benchmark.hh"
#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "ArrayLista.hh"

using namespace std;


/*!
 *\brief Funkcja glowna programu.
 */
int main(int argc, char *argv[])
{
  ofstream plik;
  int l_przejsc;
  int l_danych;
  long int sredni_czas_lista=0;
  long int sredni_czas_arraylista=0;

  int *dane;
  Benchmarker Test;

  if(argc!=3 and argc!=1)
    {
      cout<<"Nieprawidlowe wywolanie"<<endl;
      return 0;
    }
  if(argc==3)
    {
      l_przejsc=atoi(argv[1]);
      l_danych=atoi(argv[2]);
    }
  if(argc==1)
    {
      l_przejsc=10;
      l_danych=10000;
    }


 
  dane=Test.generujdane(l_danych);
  
  plik.open("benchmark_ll_lista.csv");

  for(int k=0;k<=l_danych;k+=10)
    {
      Lista *implem_lista=new Lista;
      sredni_czas_lista=Test.testuj(implem_lista,dane,l_przejsc,k);
      delete implem_lista;

      //cout<<k<<" "<<sredni_czas_lista<<endl;    
      plik<<k<<","<<sredni_czas_lista<<"\n";
    }
  
  plik.close();


  plik.open("benchmark_array_lista.csv");

  for(int k=0;k<=l_danych;k+=10)
    {
      ArrayLista *implem_arraylista=new ArrayLista;
      sredni_czas_arraylista=Test.testuj(implem_arraylista,dane,l_przejsc,k);
      delete implem_arraylista;
      
      //cout<<k<<" "<<sredni_czas_stos<<endl;    
      plik<<k<<","<<sredni_czas_arraylista<<"\n";
    }
  
  plik.close();


  return 0;
}
