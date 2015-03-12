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

  for(int k=1;k<=100000;k*=2)
    {
      sredni_czas=Tst.testuj(Tab,dane,1000,k);
      cout<<k<<" "<<sredni_czas<<endl;    
      plik<<k<<","<<sredni_czas<<"\n";

    }
  plik.close();



  return 0;
}
