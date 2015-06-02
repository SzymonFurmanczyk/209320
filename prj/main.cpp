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
  

  int *dane;
  dane=generujdane<int>(l_danych);
  
  Benchmarker<int> *Test=new Benchmarker<int>;

  Algorytm<int> *alg2 = new Algorytm2;       //Zapis na strukture
  Algorytm<int> *alg6 = new Algorytm6;       //Odczyt z drzewa
  
  Obserwator *Obs = new ObserwatorZapisujacy;
  Test->dodaj(Obs);

    
  
  //Zapis na drzewie binarnym
  for(int k=0;k<=l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new DrzewoBinarne;
    
      Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
      delete implementacja;
    }

  //Odczyt z drzewa binarnego
  for(int k=0;k<=l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new DrzewoBinarne;
    
      Test->testuj(implementacja,alg6,dane,l_przejsc,k);
    
      delete implementacja;
    }
  

  
  //Zapis na drzewie RB
  for(int k=0;k<=l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new DrzewoRB;
    
      Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
      delete implementacja;
    }

  //Odczyt z drzewa RB
  for(int k=0;k<=l_danych;k+=10)
    {
      Zasobnik<int> *implementacja=new DrzewoRB;
    
      Test->testuj(implementacja,alg6,dane,l_przejsc,k);
    
      delete implementacja;
    }
    

  
  return 0;
}
