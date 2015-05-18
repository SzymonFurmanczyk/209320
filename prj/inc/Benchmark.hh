#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmarker.
 *
 * Plik zawiera definicje klasy Benchmarker.
 */

#include "Algorytm1.hh"
#include "Algorytm2.hh"
#include "Algorytm3.hh"
#include "Algorytm4.hh"
#include "Algorytm5.hh"
#include "Algorytm6.hh"
//#include "Interfaces/AlgorytmAbs.hh"
#include "ObserwatorZapisujacy.hh"
#include "Interfaces/Obserwowany.hh"


using namespace std;

/*!
 *\brief Klasa Benchmarker.
 */
template<typename T>
class Benchmarker : public Obserwowany
{
  int iteracja;
  long int czas_sekcji;
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

  void powiadom(int, long int);
};


#endif
