#ifndef ALGORYTM6_HH
#define ALGORYTM6_HH

#include "Interfaces/AlgorytmAbs.hh"
#include "HaszTab.hh"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Algorytm6 : public Algorytm<string>
{ 
public:

  void alokujdane(HaszTab);
  void wykonajalgorytm(HaszTab);
};


#endif
