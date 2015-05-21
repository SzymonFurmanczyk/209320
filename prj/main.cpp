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
  
  
  /* 
     int *dane;
     dane=generujdane<int>(l_danych);
     
     Benchmarker<int> *Test=new Benchmarker<int>;
     Algorytm<int> *alg1 = new Algorytm1;
     Algorytm<int> *alg2 = new Algorytm2;
     Algorytm<int> *alg4 = new Algorytm4;
     
     Obserwator *Obs = new ObserwatorZapisujacy;
     Test->dodaj(Obs);
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Lista;
    
    Test->testuj(implementacja,alg1,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Lista;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Stos;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Kolejka;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new ArrayLista;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new ArrayLista;
    
    Test->testuj(implementacja,alg4,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  
  /*
    string *dane3;
    dane3=generujdane<string>(l_danych);
    
    Benchmarker<string> *Test3=new Benchmarker<string>;
    Algorytm<string> *alg3 = new Algorytm3;
    
    Obserwator *Obs2 = new ObserwatorZapisujacy;
    Test3->dodaj(Obs2);
    
    
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<string> *implementacja=new HaszTab;
    
    Test3->testuj(implementacja,alg3,dane3,l_przejsc,k);
    
    delete implementacja;
    }
  */


  
    int *dane4;
    dane4=generujdane<int>(l_danych);
    
    Benchmarker<int> *Test4=new Benchmarker<int>;
    Algorytm<int> *alg6 = new Algorytm6;
    
    Obserwator *Obs4 = new ObserwatorZapisujacy;
    Test4->dodaj(Obs4);
    
    
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Graf;
    
    Test4->testuj(implementacja,alg6,dane4,l_przejsc,k);
    
    delete implementacja;
    }
  
  
  return 0;
}
