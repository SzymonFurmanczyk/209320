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

  /*!
   *\brief Destruktor wirtualny.
   */
  virtual ~Zasobnik(){};

  /*!
   *\brief Metoda umieszczajaca element na zasobniku.
   *\param
   * wartosc - typu T, wartosc umieszczana na zasobniku.
   */
  virtual void push(T wartosc)=0;

  /*!
   *\brief Metoda zdejmujaca element z zasobnika.
   *\return
   * wartosc - typu T, wartosc zdejmowana z zasobnika.
   */
  virtual T pop()=0;

  /*!
   *\brief Metoda zwracajaca rozmiar zasobnika.
   *\return
   * rozmiar - typu int,rozmiar zasobnika.
   */
  virtual int size()=0;
};


#endif
