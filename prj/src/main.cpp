/*!
 *\file 
 *\brief Modul glowny.
 *
 * Plik zawiera funkcje main.
 */

#include <cstdlib>
#include <ctime>

#include "Benchmark.hh"

using namespace std;

/*!
 *\brief Funkcja glowna programu.
 */
int main()
{
  int* dane;
  Benchmarker Tst;
  int* Tab=NULL;
  dane=new int[1000];
  srand(time(NULL));

  for(int i=1;i<=1000;i++)
    {
      dane[i]=rand() %10000;
    }

  Tst.testuj(Tab,dane,10,10);


  return 0;
}
