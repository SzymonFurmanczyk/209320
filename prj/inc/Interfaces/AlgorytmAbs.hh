#ifndef ALGORYTMABS_HH
#define ALGORYTMABS_HH

using namespace std;

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "ArrayLista.hh"
#include "HaszTab.hh"

template <typename T>
class Algorytm
{ 
public:
  virtual ~Algorytm(){};

  virtual void alokujdane(Zasobnik<T>*,T*,int)=0;
  virtual void wykonajalgorytm(Zasobnik<T>*,T*,int)=0;
};


#endif
