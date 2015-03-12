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

using namespace std;

/*!
 *\brief Funkcja glowna programu.
 */
int main()
{
  int sredni_czas=0;
  int* dane;
  int* Tab=NULL;
  Benchmarker Tst;
  dane=new int[100000];
  srand(time(NULL));

  for(int i=1;i<=100000;i++)
    {
      dane[i]=rand() %100000;
    }

  ofstream plik;
  plik.open("benchmark.csv");

  for(int k=0;k<=10000;k+=10)
    {
      sredni_czas=Tst.testuj(Tab,dane,10,k);
      cout<<k<<" "<<sredni_czas<<endl;    
      plik<<k<<","<<sredni_czas<<"\n";

    }
  plik.close();



  return 0;
}
