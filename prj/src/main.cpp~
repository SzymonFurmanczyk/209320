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
  int il_przejsc;
  int il_danych;
  long int sredni_czas=0;

  int* dane;
  int* Tab=NULL;
  Benchmarker Tst;

  if(argc!=3 and argc!=1)
    {
      cout<<"Nieprawidlowe wywolanie"<<endl;
      return 0;
    }
  if(argc==3)
    {
      il_przejsc=atoi(argv[1]);
      il_danych=atoi(argv[2]);
    }
  if(argc==1)
    {
      il_przejsc=10;
      il_danych=10000;
    }


  dane=new int[100000];
  srand(time(NULL));
  for(int i=1;i<=100000;i++)
    {
      dane[i]=rand() %100000;
    }

  int tmp;
  Kolejka *Test=new Kolejka;

  for(int i=0;i<6;i++)
    {
      cin>>tmp;
      Test->push(tmp);
    }
  tmp=Test->size();
  cout<<endl<<tmp<<endl<<endl;

  for(int i=0;i<6;i++)
    {
      tmp=Test->pop();
      cout<<tmp<<endl;
    }

  ofstream plik;
  plik.open("benchmark.csv");
  /*
  for(int k=0;k<=il_danych;k+=10)
    {
      sredni_czas=Tst.testuj(Tab,dane,il_przejsc,k);
      //cout<<k<<" "<<sredni_czas<<endl;    
      plik<<k<<","<<sredni_czas<<"\n";

    }
  */
  plik.close();
  delete Test;
  return 0;
}
