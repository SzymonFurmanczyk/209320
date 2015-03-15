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

 /*!
 *\brief Metoda przeprowadzajaca sprawdzenie czasy dzialania  funkcji.
 *
 *\param
 * tab - typu int*, wskaznik na tablice z wartosciami.
 *\param
 * dane - typu int*, wskaznik na tablice z danymi generowanymi.
 *\param
 * liczba_przejsc - typu int, liczba przejsc przez dane.
 *\param
 * liczba_danych - typu int, liczba danych w tablicy. 
 *\return
 * czas_calkowity_usredniony - typu long int, czas sredni dzialania funkcji.
 */
long int Benchmarker::testuj(int *tab,int *dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;

  tab=new int[liczba_danych];

  for(int i=1;i<=liczba_danych;i++)
    {
      tab[i]=dane[i];
    }
  
  for(int j=1;j<=liczba_przejsc;j++)
    {
      clock_gettime(CLOCK_REALTIME, &start);
      
      for(int i=1;i<=liczba_danych;i++)
	{

	}  
      
      clock_gettime(CLOCK_REALTIME, &stop);
      
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
