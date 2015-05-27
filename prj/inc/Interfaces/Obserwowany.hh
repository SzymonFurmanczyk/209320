#ifndef OBSERWOWANY_HH
#define OBSERWOWANY_HH

/*!
 *\file 
 *\brief Definicja szablonu klasy abstrakcyjnej Obserwowany.
 *
 * Plik zawiera definicje szablonu klasy abstrakcyjnej Obserwowany.
 */

#include "Obserwator.hh"

using namespace std;

/*!
 *\brief Szablon klasy Obserwowany.
 */
class Obserwowany
{
protected:
Obserwator *obserwatorzy; 
public:
  //virtual ~Obserwowany(){};

  /*!
   *\brief Metoda dodajaca obserwatora do obiektu
   *\param
   * Obs - typu Obserwator*, wskaznik na danego obserwatora
   */
  void dodaj(Obserwator *Obs)
  {
    obserwatorzy=Obs;
  };

  /*!
   *\brief Metoda usuwajaca obserwatora z obiektu
   *\param
   * Obs - typu Obserwator*, wskaznik na danego obserwatora
   */
  void usun(Obserwator *Obs)
  {
    obserwatorzy=NULL;
  };

};


#endif
