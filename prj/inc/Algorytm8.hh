#ifndef ALGORYTM8_HH
#define ALGORYTM8_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm8.
 *
 * Plik zawiera definicje klasy Algorytm8.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm8.
 */
class Algorytm8 : public Algorytm<int>
{ 
public:
  ~Algorytm8(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
};


#endif
