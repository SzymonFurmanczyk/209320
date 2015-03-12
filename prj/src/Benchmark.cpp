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
 *\brief Konstruktor bezparametryczny .
 */
Benchmarker::Benchmarker()
{}

/*!
 *\brief Destruktor bezparametryczny.
 */
Benchmarker::~Benchmarker()
{}


 /*!
 *\brief Metoda przeprowadzajaca sprawdzenie czasy dzialania  funkcji.
 * sprawdzienie czasu dzialania mnozenia kazdego elementu tablicy razy 2.
 *\param
 * tab - typu int*, wskaznik na tablice z wartosciami.
 *\param
 * dane - typu int*, wskaznik na tablice z danymi generowanymi.
 *\param
 * liczba_przejsc - typu int, liczba przejsc przez dane.
 *\param
 * liczba_danych - typu int, liczba danych w tablicy. 
 *\return
 * czas_calkowity_usredniony - typu int, czas sredni dzialania funkcji.
 */
int Benchmarker::testuj(int* tab,int* dane,int liczba_przejsc,int liczba_danych)
{
  int czas_operacji=0;
  int czas_calkowity_usredniony=0; 
  struct timespec start,stop;

  czasy=new int[liczba_przejsc];

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
	  tab[i]=dane[i]*2;
	}  
      clock_gettime(CLOCK_REALTIME, &stop);
      
      czas_operacji = (stop.tv_nsec - start.tv_nsec);
      czasy[j]=czas_operacji;
      czas_calkowity_usredniony+=czas_operacji;
    }

  return czas_calkowity_usredniony/liczba_przejsc;

}
