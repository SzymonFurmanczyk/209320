#ifndef ALGORYTMABS_HH
#define ALGORYTMABS_HH

/*!
 *\file 
 *\brief Definicja szablonu klasy abstrakcyjnej Algorytm.
 *
 * Plik zawiera definicje szablonu klasy abstrakcyjnej Algorytm.
 */

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "ArrayLista.hh"
#include "HaszTab.hh"

using namespace std;

/*!
 *\brief Szablon klasy Algorytm.
 */
template <typename T>
class Algorytm
{ 
public:
  virtual ~Algorytm(){};

  virtual void alokujdane(Zasobnik<T>*,T*,int)=0;
  virtual void wykonajalgorytm(Zasobnik<T>*,T*,int)=0;
};


#endif
