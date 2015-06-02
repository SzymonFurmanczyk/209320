#ifndef GRAF_HH
#define GRAF_HH

/*!
 *\file 
 *\brief Definicja klasy Graf.
 *
 * Plik zawiera definicje klasy Graf.
 */

#include "Interfaces/Zasobnik.hh"

using namespace std;

/*!
 *\brief Klasa Graf.
 */
class Graf : public Zasobnik<int>
{
  int **sasiedztwo; 
  int *wierzcholki;
  int rozmiar;
  
public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   * Konstruktor inicjalizujacy drzewo binarne.
   * korzen - inicjalizowany wartoscia NULL
   * wierzcholki - inicjalizowan wartoscia NULL
   * rozmiar - inicjalizowany wartoscia 0
   */
  Graf();
  
    /*!
   *\brief Destruktor bezparametryczny grafu.
   */
  ~Graf();
  

  /*!
   *\brief Metoda umieszczajaca wierzcholek na grafie.
   *       Tworzenie odpowiednio duzej macierzy sasiedztwa.
   *\param
   * wierzch - typu int, wartosc wierzcholka umieszczanego.
   */
  void push(int);

  /*!
   *\brief Metoda umieszczajaca krawedz na grafie.
   *\param
   * wierzch_1 - typu int, pierwszy wierzcholek.
   *\param
   * wierzch_2 - typu int, drugi wierzcholek.
   *\param
   * waga - typu int, waga krawedzi.
   */
  void push(int,int,int);
  
  int pop();

  /*!
   *\brief Metoda zwracajaca wartosc danego wierzcholka
   *       zalezna od jego indeksu.
   *\param
   * indeks - typu int, wartosc szukana na drzewie binarnym.
   *\return
   * wartosc - typu int, indeks wierzcholka.
   */
  int pop(int);

  /*!
   *\brief Metoda zwracajaca wartosc danej krawedi miedzy dwoma wierzcholkami.
   *\param
   * indeks1 - typu int, wartosc indeksu pierwszego.
   *\param
   * indeks1 - typu int, wartosc indeksu drugiego.
   *\return
   * wartosc - typu int, indeks wierzcholka.
   */
  int pop(int , int);

  /*!
   *\brief Metoda zwracajaca ilosc wierzcholkow grafu.
   *\return
   * rozmiar - typu int, ilosc wezlow drzewa binarnego.
   */
  int size();
  
};


#endif
