#ifndef ALGORYTM6_HH
#define ALGORYTM6_HH

#include "Interfaces/AlgorytmAbs.hh"

using namespace std;

class Algorytm6 : public Algorytm<string>
{ 
public:

  void alokujdane(HaszTab);
  void wykonajalgorytm(HaszTab);
};


#endif
