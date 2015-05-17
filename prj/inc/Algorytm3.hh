#ifndef ALGORYTM3_HH
#define ALGORYTM3_HH

#include "Interfaces/AlgorytmAbs.hh"


using namespace std;


class Algorytm3 : public Algorytm<string>
{ 
public:

  void alokujdane(Zasobnik<string>* Tab,string* dane,int liczba_danych);
  void wykonajalgorytm(Zasobnik<string>* Tab,string* dane,int liczba_danych);
};


#endif
