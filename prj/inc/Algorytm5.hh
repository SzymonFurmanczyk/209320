#ifndef ALGORYTM5_HH
#define ALGORYTM5_HH

#include "Interfaces/AlgorytmAbs.hh"


using namespace std;

class Algorytm5 : public Algorytm<int>
{ 
public:

  void alokujdane(Zasobnik<int>*,int*,int);
  void wykonajalgorytm(Zasobnik<int>*,int*,int);
};


#endif
