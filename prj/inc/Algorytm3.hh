#ifndef ALGORYTM3_HH
#define ALGORYTM3_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm3.
 *
 * Plik zawiera definicje klasy Algorytm3.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm3.
 */
class Algorytm3 : public Algorytm<string>
{ 
public:

  void alokujdane(Zasobnik<string>* Tab,string* dane,int liczba_danych);
  void wykonajalgorytm(Zasobnik<string>* Tab,string* dane,int liczba_danych);
};


#endif
