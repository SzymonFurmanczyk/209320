#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmarker.
 *
 * Plik zawiera definicje klasy Benchmarker.
 */

#include "Observer.hh"

#include <string>

using namespace std;

/*!
 *\brief Klasa Benchmarker.
 */
class Benchmarker
{
  Observer *obs;
public:
  
  /*!
   *\brief Szablon metody przeprowadzajaca sprawdzenie czasu dzialania funkcji.
   *       Typy: Lista , Stos , Kolejka, Tablica haszująca.
   *\tparam
   * Tab - typu T*, wskaznik na zaimplementowany stos/liste/kolejke/tablice haszującą.
   *\tparam
   * dane - typu int*, wskaznik na tablice z danymi generowanymi.
   *\tparam
   * liczba_przejsc - typu int, liczba przejsc przez dane.
   *\tparam
   * liczba_danych - typu int, liczba danych w tablicy. 
   *\return
   * czas_calkowity_usredniony - typu long int, czas sredni dzialania funkcji.
   */
  template <class T,typename T2>  long int testuj(T*,T2*,int,int);
  
  /*!
   *\brief Metoda generujaca wartosci losowe z przedzialu 0 10000.
   *\param
   * l_danych - typu int, liczba generowanych danych.
   *\return
   * *dane - typu long int*, tablica z wygenerowanymi danymi.
   */
  int* generujdane(int l_danych);
  
  /*!
   *\brief Metoda generujaca wartosci losowe z przedzialu A-Z + a-z.
   *\param
   * l_danych - typu int, liczba generowanych danych.
   *\return
   * *dane - typu string*, tablica z wygenerowanymi danymi(np.: Axb CtQ).
   */
  string* generujdane_string(int l_danych);


  podlacz_obs() //dodanie obserwatora do benchmarku
  odlacz_obs()  //usuniecie obsevatora z benchmarku
  powiadom_obs() //powiadomienie obserwatora o zdarzeniu

};


#endif
