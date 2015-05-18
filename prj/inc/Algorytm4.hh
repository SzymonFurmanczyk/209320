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
  int* mergesort(int*,int);
  int* scal(int*,int*,int,int*,int);
};


#endif
