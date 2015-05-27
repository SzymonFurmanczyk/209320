#ifndef ALGORYTM5_HH
#define ALGORYTM5_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm5.
 *
 * Plik zawiera definicje klasy Algorytm5.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm5.
 */
class Algorytm5 : public Algorytm<int>
{ 
public:

  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
};


#endif
