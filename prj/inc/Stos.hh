#ifndef STOS_HH
#define STOS_HH

/*!
 *\file 
 *\brief Definicja klasy Stos.
 *
 * Plik zawiera definicje klasy Stos.
 */

using namespace std;

/*!
 *\brief Klasa Stos.
 */
class Stos : public Zasobnik<int>
{
  struct element
  {
    int kontener;
    element *nastepny;
  };
  
  element *straznik;
  int rozmiar;
  
public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   *       Konstruktor inicjalizujacy straznika 
   *       stosu wartoscia NULL ,oraz rozmiar wartoscia 0.
 */
  Stos();
  
  /*!
   *\brief Destruktor bezparametryczny stosu.
   */
  ~Stos();
  
  
  /*!
   *\brief Metoda umieszczajaca element na stosie
   *       Metoda inkrementuje rozmiar podczas umieszczania elementu na stosie.
   *\param
   * wartosc - typu int, wartosc umieszczana na stosie.
   */
  void push(int);
  
  /*!
   *\brief Metoda zdejmujaca element ze stosu.
   *       Metoda dekrementuje rozmiar przy zdejmowaniu ze stosu.
   *\return
   * wartosc - typu int, wartosc zdejmowana ze stosu.
   */
  int pop();
  
  /*!
   *\brief Metoda zwracajaca wielkosc stosu.
   *\return
   * rozmiar - typu int,rozmiar stosu.
   */
  int size();
  
};


#endif
