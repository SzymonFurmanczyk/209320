#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmarker.
 *
 * Plik zawiera definicje klasy Benchmarker.
 */
#include "Interfaces/Zasobnik.hh"
#include "Interfaces/AlgorytmAbs.hh"
#include "Interfaces/ObserwatorAbs.hh"
#include "Interfaces/ObserwowanyAbs.hh"

#include <string>

using namespace std;

/*!
 *\brief Klasa Benchmarker.
 */
template<typename T>
class Benchmarker : public Obserwowany
{
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
void testuj(Zasobnik<T>*,Algorytm<T>*,T*,int,int);

  void dodaj(Obserwator *Obs);
  void usun(Obserwator *Obs);
  void powiadom();
};


#endif
