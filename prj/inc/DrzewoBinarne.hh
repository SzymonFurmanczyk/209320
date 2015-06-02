#ifndef DRZEWOBINARNE_HH
#define DRZEWOBINARNE_HH

/*!
 *\file 
 *\brief Definicja klasy DrzewoBinarne.
 *
 * Plik zawiera definicje klasy DrzewoBinarne.
 */

#include "Interfaces/Zasobnik.hh"

using namespace std;

/*!
 *\brief Klasa DrzewoBinarne.
 */
class DrzewoBinarne : public Zasobnik<int>
{
  struct element
  {
    int* kontener;
    int il_elem;
    
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
  DrzewoBinarne();
  
  /*!
   *\brief Destruktor bezparametryczny drzewa binarnego.
   */
  ~DrzewoBinarne();

  /*!
   *\brief Metoda umieszczajaca element na drzewie binarnym.
   *\param
   * wartosc - typu int, wartosc umieszczana na drzewie binarnym.
   */
  void push(int wartosc);

  /*!
   *\brief Metoda zdejmujaca element z drzewa binarnego.
   *\return
   * wartosc - typu int, wartosc zdejmowana z drzewa binarnego.
   */
  int pop();

   /*!
   *\brief Metoda zdejmujaca dany element z drzewa binarnego.
   *\param
   * szukana - typu int, wartosc szukana na drzewie binarnym.
   *\return
   * wartosc - typu int, wartosc zdejmowana z drzewa binarnego.
   */
  int pop(int szukana);

  /*!
   *\brief Metoda zwracajaca ilosc wezlow drzewa binarnego.
   *\return
   * rozmiar - typu int, ilosc wezlow drzewa binarnego.
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
  void wypisz(element* iter,int a);

  /*!
   *\brief Metoda obracajaca w lewo dla elementu.
   *\param
   * pivot - typu element* , zadany wskaznik na element , dla ktorego wystapi obrocenie.
   *\return
   * pivot - typu element*, wskaznik na element , ktory wskoczyl za dany.
   */
  element* obroc_l(element *pivot);

  /*!
   *\brief Metoda obracajaca w prawo dla elementu.
   *\param
   * pivot - typu element* , zadany wskaznik na element , dla ktorego wystapi obrocenie.
   *\return
   * pivot - typu element*, wskaznik na element , ktory wskoczyl za dany.
   */
  element* obroc_p(element * pivot);

  /*!
   *\brief Metoda rownowazaca drzewo binarne.
   *\param
   * tmp - typu element* , zadany wskaznik , najczesciej korzen.
   *\return
   * tmp - typu element*, wskaznik na korzen.
   */
  element* rownowaz(element *tmp);


  
};


#endif
