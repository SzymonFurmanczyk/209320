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
  


  int l_przejsc;
  int l_danych;

  //long int sredni_czas=0;

  int *dane;
  Benchmarker<int> Test;
  //Algorytm1<int> alg;

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


  //dane=generujdane(l_danych);
  




  for(int k=0;k<l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new ArrayLista;

      //sredni_czas_arraylista_mergesort=
      //Test.testuj(implementacja,alg,dane,l_przejsc,k);

      delete implementacja;
     

    }
 




  return 0;
}
