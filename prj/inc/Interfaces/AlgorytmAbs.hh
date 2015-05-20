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
  /*!
   *\brief Destruktor wirtualny algorytmu.
   */
  virtual ~Algorytm(){};

  /*!
   *\brief Metoda alokujaca na zasobniku dane.
   *\param
   * Tab - typu Zasobnik<T>*, implementacja zasobnika
   *\param
   * dane - typu T*, dane wygenerowane dla implementacji
   *\param
   * liczba_danych - typu int, liczba danych dla zasobnika
   */
  virtual void alokujdane(Zasobnik<T>* Tab,T* dane,int liczba_danych)=0;

  /*!
   *\brief Metoda wykonujaca konkretny algorytm.
   *\param
   * Tab - typu Zasobnik<T>*, implementacja zasobnika
   *\param
   * dane - typu T*, dane wygenerowane dla implementacji
   *\param
   * liczba_danych - typu int, liczba danych dla zasobnika
   */
  virtual void wykonajalgorytm(Zasobnik<T>* Tab,T* dane,int liczba_danych)=0;
};


#endif
