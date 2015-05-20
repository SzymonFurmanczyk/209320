#ifndef ALGORYTM4_HH
#define ALGORYTM4_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm4.
 *
 * Plik zawiera definicje klasy Algorytm4.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm4.
 */
class Algorytm4 : public Algorytm<int>
{ 
public:
  ~Algorytm4(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
  int* mergesort(int*,int);
  int* scal(int*,int*,int,int*,int);
};


#endif
