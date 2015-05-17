#ifndef ALGORYTM2_HH
#define ALGORYTM2_HH

#include "Interfaces/AlgorytmAbs.hh"


using namespace std;

class Algorytm2 : public Algorytm<int>
{ 
public:

  void alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych);
  void wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych);
};


#endif
