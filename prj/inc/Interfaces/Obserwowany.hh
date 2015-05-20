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

  void dodaj(Obserwator *Obs)
  {
    obserwatorzy=Obs;
  };

  void usun(Obserwator *Obs)
  {
    obserwatorzy=NULL;
  };

  //void powiadom(int iteracja,long int czas_sredni)
  //{
  //obserwatorzy->odswiez(iteracja,czas_sredni);
  //};

};


#endif
