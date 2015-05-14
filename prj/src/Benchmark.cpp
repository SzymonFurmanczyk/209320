/*!
 *\file 
 *\brief Metody klasy Benchmarker.
 *
 * Plik zawiera metody klasy Benchmarker.
 */

#include "Interfaces/Zasobnik.hh"
#include "Interfaces/ObserwatorAbs.hh"
#include "Benchmark.hh"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

template<typename T>
void Benchmarker<T>::testuj(Zasobnik<T>* Tab,Algorytm<T>* Alg,T* dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;

  for(int j=1;j<=liczba_przejsc;j++)
    {

      /*
      for(int i=0;i<=liczba_danych;i++)
	{
	  Tab->push(dane[i]);
	}  
      */

      Alg.AlokujDane(Tab);


      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
     

      Alg.WykonajAlgorytm(Tab);
      /*
      Tab->mergesort();
      */

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
      
      czas_operacji = (stop.tv_nsec - start.tv_nsec);

      powiadom(czas_operacji);

      /*
      if(czas_operacji>0)
	{
	  czas_calkowity_usredniony+=czas_operacji;
	}
      else
	{
	  czas_calkowity_usredniony+=0;
	}
      */

    }
  
  //powiadom(czas_calkowity_usredniony/liczba_przejsc);
  
}

template<typename T>
void Benchmarker<T>::dodaj(Obserwator *Obs)
{
}

template<typename T>
void Benchmarker<T>::usun(Obserwator *Obs)
{
}

template<typename T>
void Benchmarker<T>::powiadom()
{
}


//template void Benchmarker::testuj<Lista,int>(Lista*,int*,int,int);
//template void Benchmarker::testuj<Stos,int>(Stos*,int*,int,int);
//template void Benchmarker::testuj<Kolejka,int>(Kolejka*,int*,int,int);
//template void Benchmarker::testuj<ArrayLista,int>(ArrayLista*,int*,int,int);
//template void Benchmarker::testuj<HaszTab,string>(HaszTab*,string*,int,int);



