/*!
 *\file 
 *\brief Metody klasy Benchmarker.
 *
 * Plik zawiera metody klasy Benchmarker.
 */

#include "Benchmark.hh"

template<typename T>
void Benchmarker<T>::testuj(Zasobnik<T>* Tab,Algorytm<T>* Alg,T* dane,int liczba_przejsc,int liczba_danych)
{
  long int czas_operacji=0;
  long int czas_calkowity_usredniony=0; 
  struct timespec start,stop;

  for(int j=1;j<=liczba_przejsc;j++)
    {

      Alg->alokujdane(Tab,dane,liczba_danych);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
     
      Alg->wykonajalgorytm(Tab,dane,liczba_danych);

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
  podaj_wynik(czas_calkowity_usredniony/liczba_przejsc);
}

template<typename T>
void Benchmarker<T>::podaj_wynik(long int)
{

}


template void Benchmarker<int>::testuj(Zasobnik<int>*,Algorytm<int>*,int*,int,int);
template void Benchmarker<string>::testuj(Zasobnik<string>*,Algorytm<string>*,string*,int,int);



