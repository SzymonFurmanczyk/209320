#ifndef ARRAYLISTA_HH
#define ARRAYLISTA_HH

/*!
 *\file 
 *\brief Definicja klasy ArrayLista.
 *
 * Plik zawiera definicje klasy modulujacej pojecie listy 
 * jednokierunkowej opartej na tablicy dynamicznej.
 */

#include "Interfaces/Zasobnik.hh"

#include <iostream>
using namespace std;

/*!
 *\brief Klasa ArrayLista.
 */
class ArrayLista : public Zasobnik<int>
{
  int rozmiar;
  int ilosc_elementow;
  int *array;
  
public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   * Konstruktor inicjalizujacy tablice listy.
   * rozmiar  - rozmiar tablicy dla listy, inicjalizowane wartoscia 1.
   * ilosc_elementow - ilosc elementow listy,inicjalizowane wartoscia 0.
   * Tworzona jest tablica dynamiczna o jednym elemencie.
   */
  ArrayLista();

  ArrayLista(int);
  
  /*!
   *\brief Destruktor bezparametryczny stosu.
   */
  ~ArrayLista();
  
  /*!
   *\brief Metoda umieszczajaca element na liscie
   *       Metoda inkrementuje rozmiar podczas umieszczania elementu na liscie.
   *\param
   * zwiekszanie - typu int, mnoznik rozszerzania tablicy
   *               podczas dodawania elementow listy .
   *\param
   * wartosc - typu int, wartosc umieszczana na stosie.
   */
  void push(int,int);
  
  /*!
   *\brief Przeciazenie operacji push.
   *       Powieksza liste podczas dodawania elementu do 200%.
   *       Nastepuje inkrementacja rozmiar listy.
   *\param
   * wartosc - typu int, wartosc umieszczana na liscie.
   */
  void push(int wartosc)
  {push(wartosc,rozmiar);};
  
  /*!
   *\brief Metoda zdejmujaca element z listy.
   *       Metoda dekrementuje ilosc_elementow przy zdejmowaniu z listy.
   *       Tablica listy jest zmniejszana podczas zdejmowania elementu o
   *       polowe gdy ilosc elementow znajdujacych sie na niej jest rowna
   *       polowie jej rozmiaru.
   *\return
   * wartosc - typu int, wartosc zdejmowana ze stosu.
   */
  int pop();
  
  /*!
   *\brief Metoda zwracajaca rozmiar tablicy na ktorej oparta jest lista.
   *\return
   * rozmiar - typu int,rozmiar tablicy listy.
   */
  int size();
  
  /*!
   *\brief Metoda zwracajaca ilosc elementow jaka znajduje sie na liscie.
   *\return
   * ilosc_elementow - typu int,ilosc elementow jaka znajduje sie na liscie.
   */
  int ile_elementow();
  
  /*!
   *\brief Metoda sortująca elementy tablicy algorytmem "mergesort".
   * Metoda dzieli główną tablicę.
   * Jest wywoływana w rekurencji.
   * Wywołuje scalanie podtablicy lewej i prawej.
   */
  void mergesort();

  /*!
   *\brief Metoda scalająca i sortująca, od najmniejszej do
   *  największej, liczby w scalanych tablicach.
   *  Sortuje te liczby do tablicy głównej.
   *\param
   * tab_l - typu ArrayLista , lewa podtablica.
   *\param
   * tab_p - typu ArrayLista , prawa podtablica.
   */
  void scal(ArrayLista* tab_l,ArrayLista* tab_p); 
};


#endif
