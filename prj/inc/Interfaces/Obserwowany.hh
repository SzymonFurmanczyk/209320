#ifndef OBSERWOWANY_HH
#define OBSERWOWANY_HH

/*!
 *\file 
 *\brief Definicja klasy .
 *
 * Plik zawiera definicje klasy .
 */

#include "Obserwator.hh"

using namespace std;

/*!
 *\brief Klasa .
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
