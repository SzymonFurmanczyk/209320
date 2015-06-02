/*!
 *\file 
 *\brief Modul glowny.
 *
 * Plik zawiera funkcje main.
 */

//#include <cstdlib>
//#include <iostream>
//#include <fstream>

#include "GeneratoryDanych.hh"
#include "Benchmark.hh"

using namespace std;


/*!	
*\brief Funkcja glowna programu.
 */
int main(int argc, char *argv[])
{

  int l_przejsc;
  int l_danych;

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

  int *dane4;
  dane4=generujdane2<int>(l_danych);
    
  Benchmarker<int> *Test4=new Benchmarker<int>;
  Algorytm<int> *alg7 = new Algorytm7;                        //DFS
  Algorytm<int> *alg8 = new Algorytm8;                        //BFS

    
  Obserwator *Obs4 = new ObserwatorZapisujacy;
  Test4->dodaj(Obs4);
    
  //Szukanie po grafie DFS
  for(int k=0;k<=l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new Graf;
      Test4->testuj(implementacja,alg7,dane4,l_przejsc,k);
      delete implementacja;
    }

  //Szukanie po grafie BFS
  for(int k=0;k<=l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new Graf;
      Test4->testuj(implementacja,alg8,dane4,l_przejsc,k);
      delete implementacja;
    }
  
  return 0;
}
