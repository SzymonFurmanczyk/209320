#ifndef ALGORYTM1_HH
#define ALGORYTM1_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm1.
 *
 * Plik zawiera definicje klasy Algorytm1.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm1.
 */
class Algorytm1 : public Algorytm<int>
{ 
public:
  ~Algorytm1(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
};


#endif
