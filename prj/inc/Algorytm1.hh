#ifndef ALGORYTM1_HH
#define ALGORYTM1_HH

#include "Interfaces/AlgorytmAbs.hh"
#include "Lista.hh"

using namespace std;

class Algorytm1 : public Algorytm<int>
{ 
public:

  void alokujdane(Lista);
  void wykonajalgorytm(Lista);
};


#endif
