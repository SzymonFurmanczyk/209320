#ifndef ARRAYLISTA_HH
#define ARRAYLISTA_HH

/*!
 *\file 
 *\brief Definicja klasy ArrayLista.
 *
 * Plik zawiera definicje klasy modulujacej pojecie listy 
 * jednokierunkowej opartej na tablicy dynamicznej.
 */

#include <iostream>
using namespace std;

/*!
 *\brief Klasa ArrayLista.
 */
class ArrayLista
{
  int rozmiar;
  int ilosc_elementow;
  int *array;
  
public:
  ArrayLista();
  ~ArrayLista();

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

  int pop();
  int size();
  int ile_elementow();
  
};


#endif
