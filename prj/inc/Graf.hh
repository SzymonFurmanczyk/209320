#ifndef GRAF_HH
#define GRAF_HH

/*!
 *\file 
 *\brief Definicja klasy Graf.
 *
 * Plik zawiera definicje klasy Graf.
 */

#include "Interfaces/Zasobnik.hh"

using namespace std;

/*!
 *\brief Klasa Graf.
 */
class Graf : public Zasobnik<int>
{
  int **sasiedztwo; 
  int *wierzcholki;
  int rozmiar;
  
public:
  
  Graf();
  
  ~Graf();
  
  void push(int);
  void push(int,int,int);
  void pushwierzcholek(int);
  void pushkrawedz(int,int,int);
  
  int pop();
  int pop(int);

  int size();
  
};


#endif
