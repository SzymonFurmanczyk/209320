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
      l_przejsc=1;
      l_danych=10000;
    }


  
  int *dane;
  dane=generujdane<int>(l_danych);

  Benchmarker<int> *Test=new Benchmarker<int>;
  Algorytm<int> *alg = new Algorytm2;

  Obserwator *Obs = new ObserwatorZapisujacy;
  Test->dodaj(Obs);
  



  /*
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new Lista;
      
      Test->testuj(implementacja,alg,dane,l_przejsc,k);
      
      delete implementacja;
    }
  
  
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new Stos;
      
      Test->testuj(implementacja,alg,dane,l_przejsc,k);
      
      delete implementacja;
    }
  
  
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new Kolejka;
      
      Test->testuj(implementacja,alg,dane,l_przejsc,k);
      
      delete implementacja;
    }
  
  
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new ArrayLista;
      
      Test->testuj(implementacja,alg,dane,l_przejsc,k);
      
      delete implementacja;
    }
  */
  
  /*
  Algorytm<int> *alg5 = new Algorytm5;
  
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new ArrayLista;
      
      Test->testuj(implementacja,alg5,dane,l_przejsc,k);
      
      delete implementacja;
    }
  */
  
  
  Algorytm<int> *alg4 = new Algorytm4;
  
  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<int> *implementacja=new ArrayLista;
      
      Test->testuj(implementacja,alg4,dane,l_przejsc,k);
      
      delete implementacja;
    }
  
  
  
  /*
  string *dane2;
  dane2=generujdane<string>(l_danych);

  Benchmarker<string> *Test2=new Benchmarker<string>;
  Algorytm<string> *alg2 = new Algorytm3;

  Obserwator *Obs2 = new ObserwatorZapisujacy;
  Test2->dodaj(Obs2);


  for(int k=0;k<l_danych;k+=100)
    {
      Zasobnik<string> *implementacja=new HaszTab;

      Test2->testuj(implementacja,alg2,dane2,l_przejsc,k);

      delete implementacja;
    }
  */

  return 0;
}
