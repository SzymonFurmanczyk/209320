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


template <class T> long int Benchmarker::testuj(T* Tab,int* dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;
  
  for(int j=1;j<=liczba_przejsc;j++)
    {
	for(int i=0;i<=liczba_danych;i++)
	{
	  Tab->push(dane[i]);
	} 
	
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
       
	Tab->mergesort(Tab);
      
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


//template long int Benchmarker::testuj<Lista>(Lista*,int*,int,int);
//template long int Benchmarker::testuj<Stos>(Stos*,int*,int,int);
//template long int Benchmarker::testuj<Kolejka>(Kolejka*,int*,int,int);
template long int Benchmarker::testuj<ArrayLista>(ArrayLista*,int*,int,int);

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
