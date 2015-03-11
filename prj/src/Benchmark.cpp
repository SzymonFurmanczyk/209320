/*!
 *\file 
 *\brief Metody klasy Benchmarker.
 *
 * Plik zawiera metody klasy Benchmarker.
 */

#include "Benchmark.hh"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>

/*!
 *\brief Inicjalizator .
 *\param
 * polozenie- typu Punkt, punkt poczatkowy manipulatora.
 *\param
 * nazwa - typu string, nazwa manipulatora.
 */
Benchmarker::Benchmarker()
{}

/*!
 *\brief Destruktor bezparametryczny.
 */
Benchmarker::~Benchmarker()
{}

void Benchmarker::testuj(int* tab,int* dane,int liczba_przejsc,int liczba_danych)
{
  long double czas_operacji;
  struct timespec start,stop;

  czasy=new long double[liczba_przejsc];

  tab=new int[liczba_danych];
  for(int i=1;i<=liczba_danych;i++)
    {
      tab[i]=dane[i];
    }

  for(int j=1;j<=liczba_przejsc;j++)
    {
      clock_gettime(CLOCK_MONOTONIC_RAW, &start);
      for(int i=1;i<=liczba_danych;i++)
	{
	  tab[i]=dane[i]*2;
	}  
      clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
      
      czas_operacji = (stop.tv_nsec - start.tv_nsec);
      czasy[j]=czas_operacji;
    }
}
