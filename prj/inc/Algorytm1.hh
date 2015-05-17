#ifndef ALGORYTM1_HH
#define ALGORYTM1_HH

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

class Algorytm1 : public Algorytm<int>
{ 
public:
  ~Algorytm1(){};
  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
};


#endif
