#ifndef ALGORYTM2_HH
#define ALGORYTM2_HH

#include "Interfaces/AlgorytmAbs.hh"
#include "Stos.hh"

using namespace std;

class Algorytm2 : public Algorytm<int>
{ 
public:

  void alokujdane(Stos);
  void wykonajalgorytm(Stos);
};


#endif
