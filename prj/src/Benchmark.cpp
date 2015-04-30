#ifndef BENCHMARK_CPP
#define BENCHMARK_CPP

/*!
 *\file 
 *\brief Metody klasy Benchmarker.
 *
 * Plik zawiera metody klasy Benchmarker.
 */

#include "Benchmark.hh"
#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "ArrayLista.hh"
#include "HaszTab.hh"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>


template <class T,typename T2> long int Benchmarker::testuj(T* Tab,T2* dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;
  string wartosc,klucz;
  string testowy_klucz;

      for(int i=0;i<liczba_danych;i++)
	{
	  istringstream strumien(dane[i]);
	  strumien>>wartosc;
	  strumien>>klucz;
	  if(i==liczba_danych/2 || i==1)
	    {
	      testowy_klucz=klucz;
	    }
	  Tab->push(wartosc,klucz);	
	}  


  for(int j=1;j<=liczba_przejsc;j++)
    {

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
     
      //cout<<Tab->odczytaj(testowy_klucz)<<endl;
      Tab->odczytaj(testowy_klucz);
      
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
      
      czas_operacji = (stop.tv_nsec - start.tv_nsec);
      if(czas_operacji>0)
	{
	  czas_calkowity_usredniony+=czas_operacji;
	}
      else
	{
	  czas_calkowity_usredniony+=0;
	}
    }
  
  return czas_calkowity_usredniony/liczba_przejsc;
  
}


//template long int Benchmarker::testuj<Lista,int>(Lista*,int*,int,int);
//template long int Benchmarker::testuj<Stos,int>(Stos*,int*,int,int);
//template long int Benchmarker::testuj<Kolejka,int>(Kolejka*,int*,int,int);
//template long int Benchmarker::testuj<ArrayLista,int>(ArrayLista*,int*,int,int);
template long int Benchmarker::testuj<HaszTab,string>(HaszTab*,string*,int,int);



int *Benchmarker::generujdane(int l_danych)
{
  int *dane=new int[l_danych];
  srand(time(NULL));
  for(int i=1;i<=l_danych;i++)
    {
      dane[i]=rand() %100000;
    }
  return dane;
}

string *Benchmarker::generujdane_string(int l_danych)
{
  int l_liter=52;
  string litery[]={"A","a","B","b","C","c","D","d","E","e","F","f","G","g",
		   "H","h","I","i","J","j","K","k","L","l","M","m","N","n",
		   "O","o","P","p","Q","q","R","r","S","s","T","t","U","u",
		   "V","v","W","w","X","x","Y","y","Z","z"};

  string *dane=new string[l_danych];

  srand(time(NULL));

  for(int i=0;i<l_danych;i++)
    {
      for(int j=0;j<6;j++)
	{
	  dane[i]=dane[i]+litery[rand() % l_liter];
	}
      
      dane[i]=dane[i]+" ";
      
      for(int j=0;j<6;j++)
	{
	  dane[i]=dane[i]+litery[rand() % l_liter];
	}
    }

  return dane;
}

#endif
