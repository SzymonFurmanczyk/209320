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

#include <cstdlib>
#include <iostream>
#include <ctime>

 /*!
 *\brief Szablon metody przeprowadzajaca sprawdzenie czasu dzialania funkcji.
 *       Typy: Lista , Stos , Kolejka.
 *\tparam
 * Tab - typu T*, wskaznik na zaimplementowany stos/liste/kolejke.
 *\tparam
 * dane - typu int*, wskaznik na tablice z danymi generowanymi.
 *\tparam
 * liczba_przejsc - typu int, liczba przejsc przez dane.
 *\tparam
 * liczba_danych - typu int, liczba danych w tablicy. 
 *\return
 * czas_calkowity_usredniony - typu long int, czas sredni dzialania funkcji.
 */
template <class T> long int Benchmarker::testuj(T* Tab,int* dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;
  
  for(int j=1;j<=liczba_przejsc;j++)
    {
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
      
      for(int i=1;i<=liczba_danych;i++)
	{
	  Tab->push(dane[i]);
	}  
      
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


template long int Benchmarker::testuj<Lista>(Lista*,int*,int,int);
template long int Benchmarker::testuj<Stos>(Stos*,int*,int,int);
template long int Benchmarker::testuj<Kolejka>(Kolejka*,int*,int,int);
template long int Benchmarker::testuj<ArrayLista>(ArrayLista*,int*,int,int);


 /*!
 *\brief Metoda generujaca wartosci losowe z przedzialu 0 10000.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * *dane - typu long int*, tablica z wygenerowanymi danymi.
 */
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

#endif
