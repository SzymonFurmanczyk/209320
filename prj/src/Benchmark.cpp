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
  long czas_operacji=0;
  long czas_calkowity=0; 
  long czas_sredni=0;
  struct timespec start;
  struct timespec stop;


  for(int j=1;j<=liczba_przejsc;j++)
    {
      start.tv_sec=0;
      start.tv_nsec=0;
      stop.tv_sec=0;
      stop.tv_nsec=0;

      Alg->alokujdane(Tab,dane,liczba_danych);

      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
      Alg->wykonajalgorytm(Tab,dane,liczba_danych);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
      
      czas_operacji=((stop.tv_sec * 1000000000) + (stop.tv_nsec))-((start.tv_sec * 1000000000) + (start.tv_nsec));
     
      czas_calkowity=czas_calkowity+czas_operacji;
    }

  czas_sredni=czas_calkowity/liczba_przejsc;
  powiadom(liczba_danych,czas_sredni);
}

template<typename T>
    void Benchmarker<T>::powiadom(int iteracja,long int czas_sredni)
{
  obserwatorzy->odswiez(iteracja,czas_sredni);
}


template void Benchmarker<int>::testuj(Zasobnik<int>*,Algorytm<int>*,int*,int,int);
template void Benchmarker<string>::testuj(Zasobnik<string>*,Algorytm<string>*,string*,int,int);



