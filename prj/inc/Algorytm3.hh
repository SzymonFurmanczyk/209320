#ifndef ALGORYTM3_HH
#define ALGORYTM3_HH

#include "Interfaces/AlgorytmAbs.hh"
#include "Kolejka.hh"

using namespace std;


class Algorytm3 : public Algorytm<int>
{ 
public:

  void alokujdane(Kolejka);
  void wykonajalgorytm(Kolejka);
};


#endif
