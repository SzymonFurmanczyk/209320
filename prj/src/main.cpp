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
  int l_przejsc;
  int l_danych;
  long int sredni_czas=0;

  int *dane;
  int *Tab=NULL;
  Benchmarker Tst;

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

  int tmp;
  Kolejka *Test=new Kolejka;

  ofstream plik;
  plik.open("benchmark.csv");
 
  dane=Tst.generujdane(l_danych);
  for(int k=0;k<=l_danych;k+=10)
    {
      sredni_czas=Tst.testuj(Tab,dane,l_przejsc,k);
      //cout<<k<<" "<<sredni_czas<<endl;    
      //plik<<k<<","<<sredni_czas<<"\n";
    }
  
  plik.close();
  delete Test;
  return 0;
}
