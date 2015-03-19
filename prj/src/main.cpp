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
  long int sredni_czas_stos=0;
  long int sredni_czas_kolejka=0;

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
      l_danych=1000;
    }
 
  dane=Test.generujdane(l_danych);


  plik.open("benchmark_lista.csv");

  for(int k=0;k<=l_danych;k+=10)
    {
      Lista *impl_lista=new Lista;
      sredni_czas_lista=Test.testuj(impl_lista,dane,l_przejsc,k);
      delete impl_lista;
      
      //cout<<k<<" "<<sredni_czas_lista<<endl;    
      plik<<k<<","<<sredni_czas_lista<<"\n";
    }
  
  plik.close();



  plik.open("benchmark_stos.csv");

  for(int k=0;k<=l_danych;k+=10)
    {
      Stos *impl_stos=new Stos;
      sredni_czas_stos=Test.testuj(impl_stos,dane,l_przejsc,k);
      delete impl_stos;
      
      //cout<<k<<" "<<sredni_czas_stos<<endl;    
      plik<<k<<","<<sredni_czas_stos<<"\n";
    }
  
  plik.close();



  plik.open("benchmark_kolejka.csv");

  for(int k=0;k<=l_danych;k+=10)
    {
      Kolejka *impl_kolejka=new Kolejka;
      sredni_czas_kolejka=Test.testuj(impl_kolejka,dane,l_przejsc,k);
      delete impl_kolejka;
      
      //cout<<k<<" "<<sredni_czas_kolejka<<endl;    
      plik<<k<<","<<sredni_czas_kolejka<<"\n";
    }
  
  plik.close();
  


  return 0;
}
