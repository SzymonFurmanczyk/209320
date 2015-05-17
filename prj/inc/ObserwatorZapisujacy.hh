#ifndef OBSERWATORZAPISUJACY_HH
#define OBSERWATORZAPISUJACY_HH

/*!
 *\file 
 *\brief Definicja klasy Stos.
 *
 * Plik zawiera definicje klasy Stos.
 */

#include "Interfaces/Obserwator.hh"

using namespace std;

/*!
 *\brief Klasa .
 */
class ObserwatorZapisujacy : public Obserwator
{ 
public:
  ~ObserwatorZapisujacy();
  void odswiez(int,long int);
};


#endif
