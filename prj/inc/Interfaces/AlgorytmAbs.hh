#ifndef ALGORYTMABS_HH
#define ALGORYTMABS_HH

using namespace std;

#include "Interfaces/Zasobnik.hh"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

template <typename T>
class Algorytm
{ 
public:
  virtual ~Algorytm() {};

  virtual void alokujdane(Zasobnik<T>*)=0;
  virtual void wykonajalgorytm(Zasobnik<T>*)=0;
};


#endif
