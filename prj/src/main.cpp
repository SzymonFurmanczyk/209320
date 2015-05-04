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
#include "HaszTab.hh"

using namespace std;


/*!
 *\brief Funkcja glowna programu.
 */
int main(int argc, char *argv[])
{
  ofstream plik;

  int l_przejsc;
  int l_danych;

  long int sredni_czas_arraylista_mergesort=0;

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


 
  //dane=Test.generujdane(l_danych);
  dane=Test.generujdane(l_danych);

  plik.open("benchmark_arraylista_mergesort.csv");


  for(int k=0;k<l_danych;k+=10)
    {
      ArrayLista *implem_arraylista_mergesort=new ArrayLista;

      sredni_czas_arraylista_mergesort=Test.testuj(implem_arraylista_mergesort,dane,l_przejsc,k);

      delete implem_arraylista_mergesort;
     
      //cout<<k<<" "<<sredni_czas_arraylista_mergesort<<endl;    
      plik<<k<<","<<sredni_czas_arraylista_mergesort<<"\n";
    }
 

  plik.close();


  return 0;
}
