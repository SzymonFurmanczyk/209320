#ifndef LISTA_HH
#define LISTA_HH

#include "Interfaces/Zasobnik.hh"

/*!
 *\file 
 *\brief Definicja klasy Lista.
 *
 * Plik zawiera definicje klasy modulujacej pojecie listy jednokierunkowej.
 */

using namespace std;

/*!
 *\brief Klasa Lista.
 */
class Lista : public Zasobnik<int>
{
  
  struct element
  {
    int kontener;
    element * nastepny;
  };
  
  element * straznik;
  int rozmiar;
  
  
public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   *       Konstruktor inicjalizujacy straznika 
   *       listy wartoscia NULL oraz rozmiar wartoscia 0.
   */
  Lista();
  
  /*!
   *\brief Destruktor bezparametryczny listy.
   */
  ~Lista();
  
  /*!
   *\brief Metoda umieszczajaca element okreslonej pozycji na liscie <0,rozmiar>.
   *       Metoda inkrementuje rozmiar podczas umieszczania elementuna liscie.
   *\param
   * wartosc - typu int, wartosc umieszczana na liscie.
   *\param
 * pozycja - typu int, pozycja na ktorej jest umieszczana wartosc.
 */
  void push(int,int);
  
  /*!
   *\brief Metoda zdejmujaca element z okreslonej pozycji listy <0,rozmiar>.
   *       Metoda dekrementuje rozmiar przy zdejmowaniu elementu.
   *\param
   * pozycja - typu int, numer elementu ktory ma byc zdjety z listy.
   *\return
   * wartosc - typu int, wartosc zdejmowana z listy.
   */
  int pop(int);
  
  /*!
   *\brief Przeciazenie operacji push. Umieszcza element domyslnie na pozycji 1.
   *       Nastepuje inkrementacja rozmiar listy.
   *\param
   * wartosc - typu int, wartosc umieszczana na liscie.
   */
  void push(int wartosc)
  {push(wartosc,1);};
  
  /*!
   *\brief Przeciazenie operacji pop dla listy. Pobiera domyslnie
   *       element listy z pozycji 1.Nastepuje dekrementacja rozmiar listy.
   *\return
   * wartosc - typu int, wartosc zdejmowana z listy.
   */
  int pop()
  {return pop(1);};
  
  /*!
   *\brief Metoda zwracajaca wielkosc listy.
   *\return
   * rozmiar - typu int,rozmiar listy.
   */
  int size();
  
};


#endif
