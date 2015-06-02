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
#include <list>

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

  virtual void push(T,T,T){};

  /*!
   *\brief Metoda zdejmujaca element z zasobnika.
   *\return
   * wartosc - typu T, wartosc zdejmowana z zasobnika.
   */
  virtual T pop()=0;

  /*!
   *\brief Metoda zdejmujaca dany element z zasobnika.
   *\param
   * szukana - typu T, wartosc szukana w zasobniku.
   *\return
   * wartosc - typu T, wartosc zdejmowana z zasobnika.
   */
  virtual T pop(T szukana)=0;

  virtual T pop(T,T){T a=0;return a;};

  /*!
   *\brief Metoda zwracajaca rozmiar zasobnika.
   *\return
   * rozmiar - typu int,rozmiar zasobnika.
   */
  virtual int size()=0;

};


#endif
