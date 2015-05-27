#ifndef DRZEWOREDBLACK_HH
#define DRZEWOREDBLACK_HH

/*!
 *\file 
 *\brief Definicja klasy DrzewoRB.
 *
 * Plik zawiera definicje klasy DrzewoRB.
 */

#include "Interfaces/Zasobnik.hh"

using namespace std;

/*!
 *\brief Klasa DrzewoRB.
 */
class DrzewoRB : public Zasobnik<int>
{
  enum typ
    {R,B};

  struct element
  {
    int* kontener;
    int il_elem;

    typ kolor;
    
    element *up;
    element *lewe_subdrzewo;
    element *prawe_subdrzewo;
  };
 
  element *korzen;
  int rozmiar;
  
public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   * Konstruktor inicjalizujacy drzewo binarne.
   * korzen - inicjalizowany wartoscia NULL
   * rozmiar - inicjalizowany wartoscia 0
   */
  DrzewoRB();
  
  /*!
   *\brief Destruktor bezparametryczny drzewa RB.
   */
  ~DrzewoRB();
  
  /*!
   *\brief Metoda umieszczajaca element na drzewie RB.
   *\param
   * wartosc - typu int, wartosc umieszczana na drzewie RB.
   */
  void push(int wartosc);

  /*!
   *\brief Metoda zdejmujaca element z drzewa RB.
   *\return
   * wartosc - typu int, wartosc zdejmowana z drzewa RB.
   */
  int pop();

   /*!
   *\brief Metoda zdejmujaca dany element z drzewa RB.
   *\param
   * szukana - typu int, wartosc szukana na drzewie RB.
   *\return
   * wartosc - typu int, wartosc zdejmowana z drzewa RB.
   */
  int pop(int szukana);

  /*!
   *\brief Metoda zwracajaca ilosc wezlow drzewa RB.
   *\return
   * rozmiar - typu int, ilosc wezlow drzewa RB.
   */
  int size();

  /*!
   *\brief Metoda wypisujaca cale drzewo.
   *       Wywoluje kolejne wypisz dla lewego oraz prawego subdrzewa korzenia.
   */
  void wypisz_pelne();

  /*!
   *\brief Metoda wypisujaca subdrzewo.
   *\param
   * iter - typu element* , zadany wskaznik na subdrzewo.
   *\param
   * a - typu int, poziom wyisywanego subdrzewa.
   */
  void wypisz(element* iter ,int a);


  /*!
   *\brief Metoda obracajaca w lewo dla elementu.
   *\param
   * pivot - typu element* , zadany wskaznik na element , dla ktorego wystapi obrocenie.
   *\return
   * pivot - typu element*, wskaznik na element , ktory wskoczyl za dany.
   */
  element* obroc_l(element * pivot);

  /*!
   *\brief Metoda obracajaca w prawo dla elementu.
   *\param
   * pivot - typu element* , zadany wskaznik na element , dla ktorego wystapi obrocenie.
   *\return
   * pivot - typu element*, wskaznik na element , ktory wskoczyl za dany.
   */
  element* obroc_p(element * pivot);

  /*!
   *\brief Metoda ukladajaca element na drzewie RB.
   *\param
   * pivot - typu element* , zadany wskaznik , najczesciej korzen.
   *\return
   * pivot - typu element*, wskaznik na element.
   */
  element* ukladaj(element* pivot);
};


#endif
