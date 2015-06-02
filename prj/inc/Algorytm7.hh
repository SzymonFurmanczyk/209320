#ifndef ALGORYTM7_HH
#define ALGORYTM7_HH

/*!
 *\file 
 *\brief Definicja klasy Algorytm7.
 *
 * Plik zawiera definicje klasy Algorytm7.
 */

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

/*!
 *\brief Klasa Algorytm7.
 */
class Algorytm7 : public Algorytm<int>
{ 
public:
  ~Algorytm7(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
  void DFS(int,int,int&,int *,Zasobnik<int>*,list<int>&);
};


#endif
