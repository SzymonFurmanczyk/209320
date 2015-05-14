#ifndef ALGORYTM5_HH
#define ALGORYTM5_HH

#include "Interfaces/AlgorytmAbs.hh"
#include "ArrayLista.hh"

using namespace std;

class Algorytm5 : public Algorytm<int>
{ 
public:

  void alokujdane(ArrayLista);
  void wykonajalgorytm(ArrayLista);
};


#endif
