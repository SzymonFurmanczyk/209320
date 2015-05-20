#ifndef ALGORYTM2_HH
#define ALGORYTM2_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm2.
 *
 * Plik zawiera definicje klasy Algorytm2.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm2.
 */
class Algorytm2 : public Algorytm<int>
{ 
public:

  void alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych);
  void wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych);
};


#endif
