#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmarker.
 *
 * Plik zawiera definicje klasy Benchmarker.
 */

using namespace std;

/*!
 *\brief Klasa Benchmarker.
 */
class Benchmarker
{
public:
  
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
  template <class T>  long int testuj(T*,int*,int,int);
  
  /*!
   *\brief Metoda generujaca wartosci losowe z przedzialu 0 10000.
   *\param
   * l_danych - typu int, liczba generowanych danych.
   *\return
   * *dane - typu long int*, tablica z wygenerowanymi danymi.
   */
  int *generujdane(int);
};


#endif
