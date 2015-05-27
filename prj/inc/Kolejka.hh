#ifndef KOLEJKA_HH
#define KOLEJKA_HH

#include "Interfaces/Zasobnik.hh"

/*!
 *\file 
 *\brief Definicja klasy Kolejka.
 *
 * Plik zawiera definicje klasy Kolejka.
 */

using namespace std;

/*!
 *\brief Klasa Kolejka.
 */
class Kolejka : public Zasobnik<int>
{
  struct element
  {
    int kontener;
    element *nastepny;
  };
  
  element *straznik_koniec;
  element *straznik_poczatek;
  int rozmiar;
  
public:
  /*!
   *\brief Konstruktor bezparametryczny.
   *       Konstruktor inicjalizujacy straznika_poczatek
   *       i straznika_koniec  kolejki wartosciami NULL ,
   *       oraz rozmiar kolejki wartoscia 0.
   */
  Kolejka();
  
  /*!
   *\brief Destruktor bezparametryczny kolejki.
   */
  ~Kolejka();
  
  /*!
   *\brief Metoda umieszczajaca element na koncu kolejki.
   *       Metoda inkrementuje rozmiar podczas umieszczania elementu w kolejce.
   *\param
   * wartosc - typu int, wartosc umieszczana na koncu kolejki.
   */
  void push(int wartosc);
  
  /*!
   *\brief Metoda zdejmujaca element z poczatku kolejki.
   *       Metoda dekrementuje rozmiar przy zdejmowaniu elementu.
   *\return
   * wartosc - typu int, wartosc zdejmowana z kolejki.
 */
  int pop();
  
  /*!
   *\brief Metoda zdejmujaca element z poczatku kolejki.
   *       Metoda dekrementuje rozmiar przy zdejmowaniu elementu.
   *\return
   * wartosc - typu int, wartosc zdejmowana z kolejki.
   */
  int pop(int a)
  {return pop();}

  /*!
   *\brief Metoda zwracajaca wielkosc kolejki.
   *\return
   * rozmiar - typu int,rozmiar kolejki.
   */
  int size();
  
};


#endif
