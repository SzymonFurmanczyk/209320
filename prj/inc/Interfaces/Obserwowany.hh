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
public:
  virtual ~Obserwowany(){};
  void dodaj(Obserwator *Obs){};
  void usun(Obserwator *Obs){};
  void powiadom(){};
};


#endif
