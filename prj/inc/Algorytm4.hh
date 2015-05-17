#ifndef ALGORYTM4_HH
#define ALGORYTM4_HH

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

class Algorytm4 : public Algorytm<int>
{ 
public:
  ~Algorytm4(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
  //void mergesort(Zasobnik<int>*);
  //void scal(ArrayLista* tab_l,ArrayLista* tab_p);
};


#endif
