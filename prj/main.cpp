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

  Algorytm<int> *alg1 = new Algorytm1;     //Mnozenie elementow tablicy statycznej
  Algorytm<int> *alg2 = new Algorytm2;       //Zapis na strukture
  Algorytm<int> *alg4 = new Algorytm4;     //Mergesort (dla arraylista)
  Algorytm<int> *alg5 = new Algorytm5;       //Odczyt wartosci
  Algorytm<int> *alg6 = new Algorytm6;     //Tymczasowo nie uzywane
  
  Obserwator *Obs = new ObserwatorZapisujacy;
  Test->dodaj(Obs);
  
  
  /*
//Sprawdzenie mnozenia kazdego elementu przez 2 na tablicy zwyklej
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Lista;
    
    Test->testuj(implementacja,alg1,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
//Zapis na liscie
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Lista;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
//Zapis na Stosie
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Stos;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
//Zapis na Kolejce
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new Kolejka;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
//Zapis na ArrayLiscie
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new ArrayLista;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  /*
//Mergesort ArrayListy
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new ArrayLista;
    
    Test->testuj(implementacja,alg4,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */
  
  
  /*
//Odczyt z tablicy haszujacej

  string *dane3;
  dane3=generujdane<string>(l_danych);
  
  Benchmarker<string> *Test3=new Benchmarker<string>;
  Algorytm<string> *alg3 = new Algorytm3;
  
  Obserwator *Obs2 = new ObserwatorZapisujacy;
  Test3->dodaj(Obs2);
  */
  /*
    for(int k=0;k<l_danych;k+=100)
    {
    Zasobnik<string> *implementacja=new HaszTab;
    
    Test3->testuj(implementacja,alg3,dane3,l_przejsc,k);
    
    delete implementacja;
    }
  */
    
  
//Zapis na drzewie binarnym
    for(int k=0;k<=l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new DrzewoBinarne;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }

//Odczyt z drzewa binarnego
    for(int k=0;k<=l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new DrzewoBinarne;
    
    Test->testuj(implementacja,alg6,dane,l_przejsc,k);
    
    delete implementacja;
    }
  

  /*
//Zapis na drzewie RB
    for(int k=0;k<=l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new DrzewoRB;
    
    Test->testuj(implementacja,alg2,dane,l_przejsc,k);
    
    delete implementacja;
    }

//Odczyt z drzewa RB
    for(int k=0;k<=l_danych;k+=100)
    {
    Zasobnik<int> *implementacja=new DrzewoRB;
    
    Test->testuj(implementacja,alg6,dane,l_przejsc,k);
    
    delete implementacja;
    }
  */

  
  return 0;
}
