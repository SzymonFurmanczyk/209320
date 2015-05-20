#ifndef ALGORYTM6_HH
#define ALGORYTM6_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm6.
 *
 * Plik zawiera definicje klasy Algorytm6.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm6.
 */
class Algorytm6 : public Algorytm<string>
{ 
public:
  ~Algorytm6(){};
  void alokujdane(Zasobnik<string>*,string*,int);
  void wykonajalgorytm(Zasobnik<string>*,string*,int);
};


#endif
