#ifndef ZASOBNIK_HH
#define ZASOBNIK_HH

/*!
 *\file 
 *\brief Definicja szablonu klasy abstrakcyjnej Zasobnik.
 *
 * Plik zawiera definicje szablonu klasy abstrakcyjnej Zasobnik.
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

/*!
 *\brief Szablon klasy Zasobnik.
 */
template<typename T>
class Zasobnik
{ 
public:
  virtual ~Zasobnik(){};
  virtual void push(T)=0;
  virtual T pop()=0;
  virtual int size()=0;
};


#endif
